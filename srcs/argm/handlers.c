/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate_ls <mgranate_ls@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 23:25:14 by mgranate          #+#    #+#             */
/*   Updated: 2023/01/22 04:04:26 by mgranate_ls      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static   int    print_error(char *s)
{
    printf("%s", s);
    return(0);
}

int check_argument(char *split)
{
    if (!split)
        return(print_error("sh: syntax error near unexpected token `newline'\n"));
    if (split[0] == '<' || split[0] == '>')
        return(print_error("sh: syntax error near unexpected token `<'\n"));
    return(1);
}

static int validate_arguments(char **split)
{
    int i;

    i = -1;
    while(split[++i])
    {
        if (split[i][1] && split[i][0] == '>' && split[i][1] == '>')
            return(check_argument(split[i + 1]));
        else if (split[i][1] && split[i][0] == '<' && split[i][1] == '<')
            return(check_argument(split[i + 1]));
        else if (split[i][0] == '>')
            return(check_argument(split[i + 1]));
        else if (split[i][0] == '<')
            return(check_argument(split[i + 1]));
    }
    return(1);
}

char	*handle_split(char *split)
{
	int		sz;
	char	*tmp;
	int		i;

	i = 0;
	sz = string().len(split, - 1);
	while (split[--sz] != '/')
		i++;
	tmp = string().substr(split, sz + 1, i);
	while (split[++i])
		split[i] = '\0';
	alloc().free_array(split);
	return (tmp);
}

int	argm_handler(char *str)
{
	t_command	*cmd;
	char		**split;
	char		*path;

	split = ft_split(str);
	if (!split || !split[0])
		return (0);
	check_expander(split, this_env());
    if (!validate_arguments(split))
    {
        alloc().free_matrix((void **) split);
        return (0);
    }
	path = string().strdup(split[0]);
    if (split[0][0] == '/') {
        split [0] = handle_split(split[0]);
    }
    cmd = cmdfunc().add(path, split);
    this_red(cmd->io);
    check_redirection(split);
    alloc().free_matrix((void **)split);
	alloc().free_array((void *)path);
	return (1);
}
