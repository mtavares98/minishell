/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 23:25:14 by mgranate          #+#    #+#             */
/*   Updated: 2023/01/06 16:50:15 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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

	split = ft_split(str, ' ');
	if (!split || !split[0])
		return (0);
	check_expander(split, this_env());
	check_redirection(split);
	path = string().strdup(split[0]);
	if (split[0][0] == '/')
		split [0] = handle_split(split[0]);
	cmd = cmdfunc().add(path, split);
	this_red(cmd->io);
	check_redirection(split);
	alloc().free_matrix((void **)split);
	alloc().free_array((void *)path);
	return (1);
}
