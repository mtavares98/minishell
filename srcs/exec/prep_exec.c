/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 13:07:44 by mtavares          #+#    #+#             */
/*   Updated: 2022/10/18 22:41:32 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/execution.h"

int	exec_builtin(t_command *cmd, char **envp)
{
	if (!string().strncmp(cmd->path, "echo", 5))
		echo(cmd, envp);
	else if (!string().strncmp(cmd->path, "cd", 3))
		cd(cmd, envp);
	else if (!string().strncmp(cmd->path, "pwd", 4))
		pwd(cmd, envp);
	else if (!string().strncmp(cmd->path, "export", 7))
		export(cmd, envp);
	else if (!string().strncmp(cmd->path, "unset", 6))
		unset(cmd, envp);
	else if (!string().strncmp(cmd->path, "env", 4))
		env(cmd, envp);
	else if (!string().strncmp(cmd->path, "exit", 5))
		exit_func(cmd, envp);
	else
		return (0);
	return (1);
}

int	exec_cmd(t_command *cmd, char **envp)
{
	int	pid;

	pid = fork();
	if (pid == -1)
		return (1);
	if (pid == 0)
	{
		if (!exec_builtin(cmd, envp))
			if (execve(cmd->path, cmd->args, envp) == -1)
				perror("Execve");
	}
}

int	**get_pipesfd(int num_cmd)
{
	int	i;
	int	**pipe_fd;

	pipe_fd = alloc().calloc(num_cmd - 1 * sizeof(int *));
	if (!pipe_fd)
		return (NULL);
	i = -1;
	while (++i < num_cmd - 1)
	{
		pipe_fd[i] = alloc().calloc(2 * sizeof(int));
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

int	prep_exec(t_command **cmd)
{
	int	num_cmd;
	int	**pipe_fd;

	num_cmd = get_total_cmd(*cmd);
	pipe_fd = NULL;
	if (!num_cmd)
		return (2);
	if (num_cmd == 1)
		exec_cmds(cmd, pipe_fd);
	pipe_fd = get_pipesfd(num_cmd);
	if (!pipe_fd)
		return (1);
	exec_cmds(cmd, pipe_fd);
}
