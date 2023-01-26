/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 16:33:42 by mtavares          #+#    #+#             */
/*   Updated: 2023/01/26 00:08:37 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <execution.h>
#include <minishell.h>

void	print_list(t_command *begin);

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

static int	prep_fds(t_command *cmd, int num_cmd)
{
	int	i;
	int	j;
	int	fd[2];

	j = -1;
	while (++j < num_cmd - 1)
	{
		if (pipe(fd) == -1)
		{
			perror("MikeShell: pipe");
			return (1);
		}
		i = 2;
		while (cmd && --i > -1)
		{
			if (i)
			{
				cmd->outfd = fd[i];
				cmd = cmd->next;
			}
			else
				cmd->infd = fd[i];
		}
	}
	return (0);
}

int	prep_red(t_command **cmd)
{
	int			fd[2];
	t_command	*tmp;
	t_red		*head;

	tmp = *cmd;
	while (tmp)
	{
		if (check_heredoc(tmp->io) && pipe(fd) == -1)
		{
			perror("MMSHELL: pipe");
			return (1);
		}
		if (prep_heredoc(tmp->io, fd))
			return (1);
		tmp = tmp->next;
	}
	tmp = *cmd;
	while (tmp)
	{
		head = tmp->io;
		this_red(head);
		if (check_red(this_red(NULL), tmp))
			return (1);
		tmp->io = *this_red(NULL);
		tmp = tmp->next;
	}
	return (0);
}

int	execution(t_command **cmd)
{
	int		cmd_num;

	cmd_num = get_num_cmd(*this());
	if (cmd_num > 1 && prep_fds(*cmd, cmd_num))
	{
		perror("MIKESHELL: pipe");
		return (1);
	}
	if (cmd_num == 1)
	{
		(*cmd)->infd = 0;
		(*cmd)->outfd = 1;
	}
	if (prep_red(cmd))
		return (1);
	if (prep_exec(cmd))
		return (1);
	return (0);
}
