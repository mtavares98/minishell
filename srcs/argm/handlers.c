/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 23:25:14 by mgranate          #+#    #+#             */
/*   Updated: 2023/01/26 16:55:45 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	print_error(char *s)
{
	printf("%s", s);
	return(0);
}

int check_argument(char *split)
{
	if (!split)
		return(print_error("bash: syntax error near unexpected token `newline'\n"));
	if (split[0] == '<' || split[0] == '>')
		return(print_error("bash: syntax error near unexpected token %c\n"));
	return(1);
}

static int validate_arguments(char **split)
{
	 int i;
	 int j;

	 i = -1;
	 j = 1;
	while(split[++i])
	{
		if (split[i][1] && split[i][0] == '>' && split[i][1] == '>')
			 j = check_argument(split[i + 1]);
		else if (split[i][1] && split[i][0] == '<' && split[i][1] == '<')
			 j = check_argument(split[i + 1]);
		else if (split[i][0] == '>')
			 j = check_argument(split[i + 1]);
		else if (split[i][0] == '<')
			 j = check_argument(split[i + 1]);
		else if (split[i][0] == '|')
			if (!split[i + 1] || split[i + 1][0] == '|')
				j = print_error("Pipes not accuratly placed\n");
		if (j == 0)
			return(j);
	}
	 return(j);
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
	int			i;

	i = -1;
	split = ft_split(str);
	if (!split || !split[0])
		return (0);
	check_expander(split, this_env());
	if (!validate_arguments(split))
	{
		alloc().free_matrix((void **) split);
		return (0);
	}
	while (split[++i])
	{
		cmd = cmdfunc().add(NULL, NULL);
		while (split[i] && split[i][0] != '|')
		{
			if (check_redirection(split, cmd, i))
				i += 2;
			else if (split[i] && split[i][0] != '|')
				add_command(split[i++], cmd);
		}
		if (!split[i])
			break ;
	}
	alloc().free_matrix((void **)split);
	return (1);
}
