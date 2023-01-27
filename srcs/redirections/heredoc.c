/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 16:25:05 by mtavares          #+#    #+#             */
/*   Updated: 2023/01/27 23:46:05 by mtavares         ###   ########.fr       */
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
