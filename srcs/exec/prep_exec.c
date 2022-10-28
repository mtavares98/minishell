/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 13:07:44 by mtavares          #+#    #+#             */
/*   Updated: 2022/10/27 18:35:31 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/execution.h"
#include "../../includes/minishell.h"

/* int	exec_builtin(t_command *cmd, char **envp)
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
} */

int	get_num_cmd(t_command *cmd)
{
	int	len;

	len = 0;
	if (!cmd)
		return (len);
	while (cmd && ++len)
		cmd = cmd->next;
	return (len);
}

int	exec_cmd(int in, int out, t_command **cmd, char **envp)
{
	if (in && dup2(in, STDIN_FILENO) == -1)
	{
		perror("dup2 in");
		return (1);
	}
	if (in)
		close(in);
	if (out != 1 && dup2(out, STDOUT_FILENO) == -1)
	{
		perror("dup2 out");
		return (1);
	}
	if (out != 1)
		close(out);
	if (execve((*cmd)->path, (*cmd)->args, envp) == -1)
		perror("Execve");
	return (0);
}

int	name(int in, int out, t_command **cmd, char **envp)
{
	int	pid;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (2);
	}
	if (pid == 0)
		exec_cmd(in, out, cmd, envp);
	if (in)
		close(in);
	if (out != 1)
		close(out);
	return (0);
}

int	handle_process(int **pipe_fd, t_command **cmd, char **envp)
{
	int	num_cmd;
	int	i;

	num_cmd = get_num_cmd(*cmd);
	i = -1;
	if (pipe(pipe_fd[++i]) == -1)
	{
		perror("pipe1");
		return (1);
	}
	name(0, pipe_fd[i][1], cmd, envp);
	cmdfunc().remove(0);
	while (++i < num_cmd - 1)
	{
		if (pipe(pipe_fd[i]) == -1)
		{
			perror("pipe2");
			return (1);
		}
		name(pipe_fd[i - 1][0], pipe_fd[i][1], cmd, envp);
		cmdfunc().remove(0);
	}
	name(pipe_fd[i - 1][0], 1, cmd, envp);
	i = -1;
	while (++i < num_cmd)
		wait(NULL);
	cmdfunc().remove(0);
	return (0);
}

int	prep_exec(t_command **cmd, char **envp)
{
	int	**pipe_fd;
	int	num_cmd;

	num_cmd = get_num_cmd(*cmd);
	if (!num_cmd)
		return (2);
	if (num_cmd == 1)
	{
		name(0, 1, cmd, envp);
		wait(NULL);
		return (0);
	}
	pipe_fd = get_pipesfd(num_cmd);
	if (!pipe_fd)
	{
		perror("pipe malloc");
		return (1);
	}
	if (handle_process(pipe_fd, cmd, envp))
		return (1);
	return (0);
}
