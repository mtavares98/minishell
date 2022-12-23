/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 16:25:05 by mtavares          #+#    #+#             */
/*   Updated: 2022/12/23 16:32:58 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cmd.h"

static int	fill_heredoc(int fd, char *delimiter)
{
	char	*s;

	s = NULL;
	while (string().strncmp(delimiter, s, string().len(delimiter, -1)))
	{
		if (s)
			free(s);
		write(1, "> ", 2);
		s = get_next_line(0);
		if (!s)
			return (1);
		write(fd, s, string().len(s, -1));
	}
	close(fd);
	if (!s)
		return (1);
	free(s);
	return (0);
}

static int	fork_heredoc(int fd, char *delimiter)
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
		if (fill_heredoc(fd, delimiter))
			exit (1);
		exit(0);
	}
	return (0);
}

int	prep_heredoc(t_red *io)
{
	int	fd[2];

	while (io)
	{
		if (io->file && io->is_double && !io->is_output)
		{
			if (pipe(fd) == -1)
			{
				perror("pipe");
				return (1);
			}
			io->fd = fd[0];
			if (fork_heredoc(fd[1], io->file))
			{
				close(io->fd);
				return (1);
			}
		}
		io = io->next;
	}
	return (0);
}
