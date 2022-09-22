/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 16:33:42 by mtavares          #+#    #+#             */
/*   Updated: 2022/09/21 16:34:04 by mtavares         ###   ########.fr       */
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
	if (check_files((cmd), pathenv + 5))
		return (2);
	printf("%s\n", cmdfunc().get(0)->path);
	printf("%s\n", cmdfunc().get(1)->path);
	//prep_exec(cmd, red);
	unlink(red->infile);
	unlink(red->outfile);
	cmdfunc().remove(0);
	cmdfunc().remove(0);
	return (0);
}
