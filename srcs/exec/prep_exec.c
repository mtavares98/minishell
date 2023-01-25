/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 13:07:44 by mtavares          #+#    #+#             */
/*   Updated: 2023/01/25 23:37:00 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <execution.h>
#include <minishell.h>

void	print_list(t_command *begin);

int	exec_cmd(int *in, int *out, t_command **cmd)
{
	char	b;
	char	*pathenv;

	b = 0;
	pathenv = getpath(this_env()->env);
	b = check_files(*cmd, pathenv + 5 * (pathenv != NULL));
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
	if ((*cmd)->path && !b && \
	execve((*cmd)->path, (*cmd)->args, this_env()->env) == -1)
		perror("Execve");
	free_memory(this());
	if (this_env()->env)
		alloc().free_matrix((void **)this_env()->env);
	rl_clear_history();
	exit(EXIT_FAILURE);
}

void	child_process(t_command **cmd)
{
	close_fd_exeption(this(), (*cmd)->infd, (*cmd)->outfd);
	if ((*cmd)->path && is_builtin((*cmd)->path))
	{
		(this_env())->status = exec_builtins((*cmd)->outfd, cmd);
		free_memory(cmd);
		if ((this_env())->env)
			alloc().free_matrix((void **)(this_env())->env);
		rl_clear_history();
		exit((this_env())->status);
	}
	exec_cmd(&(*cmd)->infd, &(*cmd)->outfd, cmd);
}

int	init_fork(t_command **cmd, int num_cmd)
{
	int	pid;

	if ((*cmd)->path && is_builtin((*cmd)->path) && num_cmd == 1)
	{
		(this_env())->status = exec_builtins((*cmd)->outfd, cmd);
		return ((this_env())->status);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (2);
	}
	if (pid == 0)
		child_process(cmd);
	close_fd(&(*cmd)->infd, &(*cmd)->outfd);
	return (0);
}

static void	handle_process(t_command **cmd)
{
	int	num_cmd;
	int	i;

	num_cmd = get_num_cmd(*cmd);
	i = 0;
	init_fork(cmd, num_cmd);
	cmdfunc().remove(0);
	while (++i < num_cmd - 1)
	{
		init_fork(cmd, num_cmd);
		cmdfunc().remove(0);
	}
	init_fork(cmd, num_cmd);
	cmdfunc().remove(0);
	i = -1;
	while (++i < num_cmd)
		wait(&(this_env())->status);
	update_status(this_env());
	free_memory(cmd);
}

int	prep_exec(t_command **cmd)
{
	int	num_cmd;

	num_cmd = get_num_cmd(*cmd);
	if (!num_cmd)
		return (2);
	if (num_cmd == 1)
	{
		init_fork(cmd, num_cmd);
		if (!is_builtin((*cmd)->path))
		{
			wait(&(this_env())->status);
			update_status(this_env());
		}
		free_memory(cmd);
		return (0);
	}
	handle_process(cmd);
	return (0);
}
