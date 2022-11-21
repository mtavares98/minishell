/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 13:07:44 by mtavares          #+#    #+#             */
/*   Updated: 2022/11/13 18:10:08 by mtavares         ###   ########.fr       */
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

int	exec_cmd(int *in, int *out, t_command **cmd)
{
	char	b;

	b = 0;
	if (!b && *in && dup2(*in, STDIN_FILENO) == -1)
	{
		perror("dup2 in");
		b = 1;
	}
	if (!b && *out != 1 && dup2(*out, STDOUT_FILENO) == -1)
	{
		perror("dup2 out");
		b = 1;
	}
	close_fd(in, out);
	if (!b && execve((*cmd)->path, (*cmd)->args, this_env()->env) == -1)
		perror("Execve");
	free_memory(this(), this_env());
	if (this_env()->env)
		alloc().free_matrix((void **)this_env()->env);
	rl_clear_history();
	exit(EXIT_FAILURE);
}

int	name(int *in, int *out, t_command **cmd)
{
	int	pid;

	if (is_builtin((*cmd)->path) && *in == 0 && *out == 1)
	{
		this_env()->status = exec_builtins(*out, cmd);
		return(this_env()->status);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (2);
	}
	if (pid == 0)
	{
		close_fd_exeption(this_env(), *in, *out);
		if (is_builtin((*cmd)->path))
		{
			this_env()->status = exec_builtins(*out, cmd);
			free_memory(cmd, this_env());
			if (this_env()->env)
				alloc().free_matrix((void **)this_env()->env);
			rl_clear_history();
			exit(this_env()->status);
		}
		exec_cmd(in, out, cmd);
	}
	close_fd(in, out);
	return (0);
}

static void	handle_process(t_env *env, t_command **cmd)
{
	int	num_cmd;
	int	i;
	int	tmp;

	num_cmd = get_num_cmd(*cmd);
	tmp = 0;
	i = 0;
	name(&tmp, &env->pipe[i][1], cmd);
	cmdfunc().remove(0);
	while (++i < num_cmd - 1)
	{
		name(&env->pipe[i - 1][0], &env->pipe[i][1], cmd);
		cmdfunc().remove(0);
	}
	tmp = 1;
	name(&env->pipe[i - 1][0], &tmp, cmd);
	cmdfunc().remove(0);
	i = -1;
 	while (++i < num_cmd)
		wait(&env->status);
	update_status(env);
	free_memory(cmd, env);
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
		{
			wait(NULL);
			update_status(this_env());
		}
		free_memory(cmd, this_env());
		return (0);
	}
	this_env()->pipe = get_pipesfd(num_cmd);
	if (!this_env()->pipe)
	{
		perror("pipe malloc");
		return (1);
	}
	handle_process(this_env(), cmd);
	return (0);
}
