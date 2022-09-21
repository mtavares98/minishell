/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 13:07:44 by mtavares          #+#    #+#             */
/*   Updated: 2022/09/21 13:41:28 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/execution.h"

int	exec_cmds(t_command **cmd, t_redirection *red, int **pipe_fd)
{
	if (pipe(pipe_fd) == -1)
		return (1);
}

int	**get_pipesfd(int num_cmd)
{
	int	i;
	int	**pipe_fd;

	pipe_fd = alloc().calloc(num_cmd - 1, sizeof(int *));
	if (!pipe_fd)
		return (NULL);
	i = -1;
	while (++i < num_cmd - 1)
	{
		pipe_fd[i] = alloc().calloc(2, sizeof(int));
		if (!pipe_fd[i])
		{
			alloc().free_matrix(pipe_fd);
			return (NULL);
		}
	}
	return (pipe_fd);
}

int	get_total_cmd(t_command *cmd)
{
	int	num_cmd;

	num_cmd = 0;
	while (cmd)
	{
		num_cmd++;
		cmd->next;
	}
	return (num_cmd);
}

int	prep_exec(t_command **cmd, t_redirection *red)
{
	int	num_cmd;
	int	**pipe_fd;

	num_cmd = get_total_cmd(*cmd);
	pipe_fd = NULL;
	if (!num_cmd)
		return (2);
	if (num_cmd == 1)
		exec_cmds(cmd, red, pipe_fd);
	pipe_fd = get_pipesfd(num_cmd);
	if (!pipe_fd)
		return (1);
	exec_cmds(cmd, red, pipe_fd);
}
