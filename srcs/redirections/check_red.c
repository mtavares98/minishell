/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_red.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 23:32:04 by mtavares          #+#    #+#             */
/*   Updated: 2023/01/26 15:03:02 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <execution.h>

static int	check_io_dup(t_red *red)
{
	t_red	*tmp;

	tmp = red;
	tmp = tmp->next;
	while (tmp)
	{
		if (red->is_output == tmp->is_output)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

static int	treat_output(t_red **red, t_command *cmd)
{
	if ((*red)->is_double)
		(*red)->fd = open((*red)->file, O_CREAT | O_APPEND | O_WRONLY, 0644);
	else
		(*red)->fd = open((*red)->file, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if ((*red)->fd == -1)
	{
		perror("MMSHELL: open");
		return (1);
	}
	if (!check_io_dup(*red))
	{
		if (cmd->outfd != -1 && cmd->outfd != 1)
			close(cmd->outfd);
		cmd->outfd = (*red)->fd;
	}
	else
		close((*red)->fd);
	return (0);
}

static int	treat_input(t_red **red, t_command *cmd)
{
	if (!(*red)->is_double)
		(*red)->fd = open((*red)->file, O_RDONLY);
	if ((*red)->fd == -1)
	{
		perror("MMSHELL: open");
		return (1);
	}
	if (check_io_dup(*red))
	{
		close((*red)->fd);
		return (0);
	}
	if (cmd->infd != -1 && cmd->infd != 0)
		close(cmd->infd);
	cmd->infd = (*red)->fd;
	return (0);
}

int	check_red(t_red **red, t_command *cmd)
{
	while (*this_red(NULL))
	{
		if (!(*red)->is_output)
			if (treat_input(red, cmd))
				return (1);
		if ((*red)->is_output)
			if (treat_output(red, cmd))
				return (1);
		(redfunc()).remove_referenece(*red, this_red(NULL));
	}
	return (0);
}
