/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 19:43:44 by mgranate          #+#    #+#             */
/*   Updated: 2023/01/26 16:53:25 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*handle_path(char *split)
{
	int		sz;
	char	*tmp;
	int		i;

	i = 0;
	sz = string().len(split, -1);
	while (split[--sz] != '/')
		i++;
	tmp = string().substr(split, sz + 1, i);
	if (!tmp)
		return (NULL);
	while (split[++i])
		split[i] = '\0';
	alloc().free_array(split);
	return (tmp);
}

int	add_command(char *split, t_command *cmd)
{
	char	**tmp;
	int		j;
	int		args_num;

	args_num = -1 * (cmd->args != NULL);
	while (cmd->args && cmd->args[++args_num])
		;
	if (!cmd->path)
		cmd->path = string().strdup(split);
	if (!cmd->path)
		return (0);
	tmp = cmd->args;
	cmd->args = alloc().calloc((args_num + 2) * sizeof(char *));
	if (!cmd->args)
	{
		cmd->args = tmp;
		return (0);
	}
	j = -1;
	while (++j < args_num)
		cmd->args[j] = tmp[j];
	cmd->args[j] = string().strdup(split);
	if (!cmd->args[j])
		return (0);
	return (1);
}

int	get_redirections(char *split, t_command *cmd, int i)
{
	char	*file;

	file = string().strdup(split);
	if (!file)
		return (0);
	if (i == 1)
		(redfunc()).add(file, 0, 1, &cmd->io);
	if (i == 2)
		(redfunc()).add(file, 1, 1, &cmd->io);
	if (i == 3)
		(redfunc()).add(file, 0, 0, &cmd->io);
	if (i == 4)
		(redfunc()).add(file, 1, 0, &cmd->io);
	return (1);
}

int	check_redirection(char **split, t_command *cmd, int i)
{
	if (split[i][0] != '>' && split[i][0] != '<')
		return (0);
	if (split[i][1] && split[i][0] == '>' && split[i][1] == '>')
		get_redirections(split[i + 1], cmd, 2);
	else if (split[i][1] && split[i][0] == '<' && split[i][1] == '<')
		get_redirections(split[i + 1], cmd, 4);
	else if (split[i][0] == '>')
		get_redirections(split[i + 1], cmd, 1);
	else if (split[i][0] == '<')
		get_redirections(split[i + 1], cmd, 3);
	return (1);
}
