/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 19:43:44 by mgranate          #+#    #+#             */
/*   Updated: 2023/01/25 22:09:52 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*handle_path(char *split)
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

int	add_command(char **split, t_command *cmd, int i)
{
	int	j;

	cmd->args = alloc().calloc((list_size(split + i, "<|>") + 1) * sizeof(char *));
	j = 0;
	cmd->path = string().strdup(split[i]);
	if (string().strchr(split[i], '/'))
		split[i] = handle_path(split[i]);
	while (split[i] && split[i][0] != '|' && split[i][0] != '<' && split[i][0] != '>')
		cmd->args[j++] = string().strdup(split[i++]);
	return(i);
}

int	get_redirections(char *split, t_command *cmd, int i)
{
	char *file;

	file = string().strdup(split);
	if (!file)
		  return (0);
	if (i == 1)
		redfunc().add(file, 0, 1, &cmd->io);
	if (i == 2)
		redfunc().add(file, 1, 1, &cmd->io);
	if (i == 3)
		redfunc().add(file, 0, 0, &cmd->io);
	if (i == 4)
		redfunc().add(file, 1, 0, &cmd->io);
	return (1);
}

int	check_redirection(char **split, t_command *cmd, int i)
{
	if(split[i][0] != '>' && split[i][0] != '<')
		return(0);
	if (split[i][1] && split[i][0] == '>' && split[i][1] == '>')
		get_redirections(split[i + 1], cmd, 2);
	else if (split[i][1] && split[i][0] == '<' && split[i][1] == '<')
		get_redirections(split[i + 1],  cmd, 4);
	else if (split[i][0] == '>')
		get_redirections(split[i + 1], cmd, 1);
	else if (split[i][0] == '<')
		get_redirections(split[i + 1], cmd, 3);
	return (1);
}