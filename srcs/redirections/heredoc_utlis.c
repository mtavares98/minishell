/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utlis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 23:39:40 by mtavares          #+#    #+#             */
/*   Updated: 2023/01/27 23:46:13 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	control_d_her(char *str, char *delimiter)
{
	if (str)
		return ;
	rl_clear_history();
	printf_fd(2, "MMSHELL: warning: expected `%s'\n", delimiter);
	if (this_env()->env)
		alloc().free_matrix((void **)this_env()->env);
	free_memory(this());
	exit(this_env()->status);
}

static void	gen_handler_her(int signal)
{
	if (signal == SIGQUIT)
		return ;
	if (signal == SIGINT)
	{
		(this_env())->status = 130;
		write(1, "\n", 1);
		exit((this_env())->status);
	}
	return ;
}

static int	fill_heredoc(int fd, char *delimiter)
{
	char	*s;

	s = NULL;
	signal(SIGQUIT, gen_handler_her);
	signal(SIGINT, gen_handler_her);
	while (string().strncmp(delimiter, s, string().len(delimiter, -1)))
	{
		if (s)
			free(s);
		s = readline("> ");
		if (!s)
		{
			if (fd != -1)
				close(fd);
			control_d_her(s, delimiter);
		}
		if (string().strncmp(delimiter, s, string().len(delimiter, -1)))
		{
			s = her_expander(s, this_env());
			printf_fd(fd, "%s\n", s);
		}
	}
	if (fd != -1)
		close(fd);
	free(s);
	return (0);
}

void	close_fd_red(t_command **cmd, int *fd, int fd_used)
{
	t_command	*cmd_tmp;
	t_red		*io_tmp;

	cmd_tmp = *cmd;
	if (fd[0] != -1)
		close(fd[0]);
	if (fd[1] != -1 && fd[1] != fd_used)
		close(fd[1]);
	close_fd_exeption(this(), fd[0], fd[1]);
	while (cmd_tmp)
	{
		io_tmp = cmd_tmp->io;
		while (io_tmp)
		{
			if (io_tmp->fd != -1)
				close(io_tmp->fd);
			io_tmp = io_tmp->next;
		}
		cmd_tmp = cmd_tmp->next;
	}
}

static int	child_heredoc(int fd, char *delimiter, int *fd_not_used)
{
	int	status;

	close_fd_red(this(), fd_not_used, fd);
	status = fill_heredoc(fd, delimiter);
	free_memory(this());
	if (this_env()->env)
		alloc().free_matrix((void **)this_env()->env);
	rl_clear_history();
	exit(status);
}

int	fork_heredoc(int fd, char *delimiter, int *fd_not_used)
{
	int		pid;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (1);
	}
	if (pid == 0)
		child_heredoc(fd, delimiter, fd_not_used);
	else
	{
		wait(&this_env()->status);
		update_status(this_env());
	}
	return (0);
}
