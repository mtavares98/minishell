/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 16:25:05 by mtavares          #+#    #+#             */
/*   Updated: 2023/01/27 23:26:01 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <execution.h>
#include <get_next_line.h>

int	check_heredoc(t_red *io)
{
	while (io)
	{
		if (io->is_double && !io->is_output)
			return (1);
		io = io->next;
	}
	return (0);
}

static int	fill_heredoc(int fd, char *delimiter)
{
	char	*s;

	s = NULL;
	while (string().strncmp(delimiter, s, string().len(delimiter, -1)))
	{
		if (s)
			free(s);
		printf_fd(1, "> ");
		s = get_next_line(0);
		if (!s)
			return (1);
		if (string().strncmp(delimiter, s, string().len(delimiter, -1)))
		{
			s = her_expander(s, this_env());
			printf_fd(fd, "%s", s);
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

static int	fork_heredoc(int fd, char *delimiter, int *fd_not_used)
{
	int		pid;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (1);
	}
	if (pid == 0)
	{
		close_fd_red(this(), fd_not_used, fd);
		if (fill_heredoc(fd, delimiter))
			exit (1);
		exit(0);
	}
	else
	{
		wait(&this_env()->status);
		update_status(this_env());
	}
	return (0);
}

int	prep_heredoc(t_red *io, int *fd)
{
	int	bol;

	bol = -1;
	while (io)
	{
		if (io->file && io->is_double && !io->is_output)
		{
			if (check_heredoc(io->next))
				bol = fork_heredoc(-1, io->file, fd);
			else
			{
				bol = fork_heredoc(fd[1], io->file, fd);
				close(fd[1]);
				io->fd = fd[0];
			}
			if (bol)
			{
				close(fd[0]);
				return (1);
			}
		}
		io = io->next;
	}
	return (0);
}
