/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 16:33:42 by mtavares          #+#    #+#             */
/*   Updated: 2022/09/19 17:47:06 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/execution.h"

void	write_heredoc(t_redirection *red)
{
	char	*s;

	s = NULL;
	while (string().strncmp(red->limiter, s, \
	(size_t)string().len(red->limiter, -1)))
	{
		if (s)
			alloc().free_array(s);
		write(1, "heredoc>", 8);
		s = get_next_line(0);
		write(red->infd, s, string().len(s, -1));
	}
	if (s)
		alloc().free_array(s);
}

int	files_checking(t_command **cmd, char *pathenv)
{
	t_command	*tmp;
	char		*path;

	if (!*cmd)
		return (0);
	tmp = *cmd;
	while (tmp)
	{
		path = pathenv;
		if (access(tmp->path, F_OK) != -1)
			tmp->ready = 1;
		while (path && !tmp->ready)
		{
			if (tmp->path)
				alloc().free_array(tmp->path);
			tmp->path = get_complete_path(tmp->args[0], &path);
			if (access(tmp->path, F_OK) != -1)
				break ;
			if (!*path)
				return (3);
		}
		tmp = tmp->next;
	}
	return (0);
}

int	open_redirections(t_redirection *red)
{
	if (red->infile && !string().strncmp(red->infile, ".heredoc", 9))
	{
		red->infd = open(red->infile, O_CREAT | O_TRUNC | O_RDWR, 0644);
		if (red->infd == -1)
			return (1);
	}
	else if (red->infile && !red->infd)
	{
		red->infd = open(red->infile, O_RDONLY);
		if (red->infd == -1)
			return (1);
	}
	if (red->outfile && red->is_trunc)
	{
		red->outfd = open(red->outfile, O_CREAT | O_TRUNC | O_WRONLY, 0644);
		if (red->outfd == -1)
			return (1);
	}
	else if (red->outfile && !red->is_trunc)
	{
		red->outfd = open(red->outfile, O_CREAT | O_APPEND | O_WRONLY, 0644);
		if (red->outfd == -1)
			return (1);
	}
	return (0);
}

int	exec_main(t_command **cmd, t_redirection *red, char **envp)
{
	char	*pathenv;

	if (open_redirections(red))
	{
		perror("open error\n");
		return (1);
	}
	if (!string().strncmp(red->infile, ".heredoc", 9))
		write_heredoc(red);
	pathenv = getpath(envp);
	if (files_checking((cmd), pathenv + 5))
		return (2);
	printf("%s\n", cmdfunc().get(0)->path);
	printf("%s\n", cmdfunc().get(1)->path);
	unlink(red->infile);
	printf("%s\n", cmdfunc().get(0)->path);
	printf("%s\n", cmdfunc().get(1)->path);
	unlink(red->outfile);
	cmdfunc().remove(0);
	cmdfunc().remove(0);
	return (0);
}
