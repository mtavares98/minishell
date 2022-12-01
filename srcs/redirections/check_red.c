/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_red.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 23:32:04 by mtavares          #+#    #+#             */
/*   Updated: 2022/12/01 13:40:19 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/red.h"

static int	check_io_dup(t_red *red)
{
	t_red	*tmp;

	tmp = red;
	while (tmp)
	{
		if (red->is_output == tmp->is_output)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

static int	treat_output(t_red *red, t_command *cmd)
{
	if (cmd->outfd != -1)
		close(cmd->outfd);
	if (red->is_double)
	{
		cmd->outfd = open(red->file, O_CREAT | O_APPEND | O_WRONLY, 0644);
		if (cmd->outfd == -1)
		{
			perror("MMSHELL: open");
			return (1);
		}
	}
	else if (!red->is_double)
	{
		cmd->outfd = open(red->file, O_CREAT | O_TRUNC | O_WRONLY, 0644);
		if (cmd->outfd == -1)
		{
			perror("MMSHELL: open");
			return (1);
		}
	}
	if (check_io_dup(red))
		redfunc().remove_referenece(red);
}

static int	treat_input(t_red *red, t_command *cmd)
{
	if (check_io_dup(red))
	{
		if (red->is_double)
			close(red->fd);
		redfunc().remove_referenece(red);
		return (0);
	}
	if (cmd->infd != -1)
		close(cmd->infd);
	if (!red->is_double)
		cmd->infd = open(red->file, O_RDONLY);
	else
		cmd->infd = red->fd;
	if (cmd->infd == -1)
	{
		perror("MMSHELL: open");
		return (1);
	}
	return (0);
}

int	check_red(t_red *red, t_command *cmd)
{
	if (!red->is_output)
		return (treat_input(red, cmd));
	if (red->is_output)
		return (treat_output);
}
