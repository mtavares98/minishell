/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utlis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 23:39:40 by mtavares          #+#    #+#             */
/*   Updated: 2023/01/31 14:13:10 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	*fd_used(int *data)
{
	static int	*fd_used;

	if (data)
		fd_used = data;
	return (fd_used);
}

static void	control_d_her(char *str, char *delimiter)
{
	int	fd;

	if (str)
		return ;
	fd = *fd_used(NULL);
	if (fd != -1)
		close(fd);
	rl_clear_history();
	printf_fd(2, "MMSHELL: warning: expected `%s'\n", delimiter);
	if (this_env()->env)
		alloc().free_matrix((void **)this_env()->env);
	free_memory(this());
	exit(this_env()->status);
}

static void	gen_handler_her(int signal)
{
	int	fd;

	if (signal == SIGQUIT)
		return ;
	if (signal == SIGINT)
	{
		fd = *fd_used(NULL);
		if (fd != -1)
			close(fd);
		(this_env())->status = 130;
		write(1, "\n", 1);
		exit((this_env())->status);
	}
}

int	fill_heredoc(int fd, char *delimiter)
{
	char	*s;

	signal(SIGQUIT, gen_handler_her);
	signal(SIGINT, gen_handler_her);
	s = NULL;
	fd_used(&fd);
	while (string().strncmp(delimiter, s, string().len(delimiter, -1)))
	{
		if (s)
		{
			s = her_expander(s, this_env());
			printf_fd(fd, "%s\n", s);
			free(s);
		}
		s = readline("> ");
		if (!s)
			control_d_her(s, delimiter);
	}
	if (fd != -1)
		close(fd);
	free(s);
	return (0);
}
