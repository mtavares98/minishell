/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 13:07:44 by mtavares          #+#    #+#             */
/*   Updated: 2022/10/31 21:00:58 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/execution.h"
#include "../../includes/minishell.h"

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

int	exec_cmd(int in, int out, t_command **cmd)
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
	if (execve((*cmd)->path, (*cmd)->args, this_env()->env) == -1)
	{
		perror("Execve");
		exit(EXIT_FAILURE);
	}
	return (this_env()->status);
}

int	name(int *in, int *out, t_command **cmd)
{
	int	pid;

	if (!is_builtin((*cmd)->path) || *in || *out != 1)
	{
		pid = fork();
		if (pid == -1)
		{
			perror("fork");
			return (2);
		}
		if (pid == 0)
		{
			if (is_builtin((*cmd)->path))
			{
				this_env()->status = exec_builtins(*out, cmd);
				free_memory(cmd, this_env());
				alloc().free_matrix((void **)this_env()->env);
				exit (this_env()->status);
			}
			exec_cmd(*in, *out, cmd);
		}
	}
	else
		exec_builtins(*out, cmd);
	close_fd(in, out);
	return (0);
}

void	handle_process(int **pipe_fd, t_command **cmd)
{
	int	num_cmd;
	int	i;
	int	tmp;

	num_cmd = get_num_cmd(*cmd);
	i = -1;
	tmp = 0;
	name(&tmp, &pipe_fd[++i][1], cmd);
	cmdfunc().remove(0);
	while (++i < num_cmd - 1)
	{
		name(&pipe_fd[i - 1][0], &pipe_fd[i][1], cmd);
		cmdfunc().remove(0);
	}
	tmp = 1;
	name(&pipe_fd[i - 1][0], &tmp, cmd);
	i = -1;
	while (++i < num_cmd)
		wait(&this_env()->status);
	cmdfunc().remove(0);
}

int	prep_exec(t_command **cmd)
{
	int	num_cmd;
	int	in;
	int	out;

	num_cmd = get_num_cmd(*cmd);
	if (!num_cmd)
		return (2);
	if (num_cmd == 1)
	{
		in = 0;
		out = 1;
		name(&in, &out, cmd);
		if (!is_builtin((*cmd)->path))
			wait(&this_env()->status);
		return (0);
	}
	this_env()->pipe = get_pipesfd(num_cmd);
	if (!this_env()->pipe)
	{
		perror("pipe malloc");
		return (1);
	}
	handle_process(this_env()->pipe, cmd);
	free_memory(cmd, this_env());
	return (0);
}
