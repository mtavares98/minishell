/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_red.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 23:32:04 by mtavares          #+#    #+#             */
/*   Updated: 2022/11/28 00:31:19 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/red.h"

int	check_io_dup(t_red *red)
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

int	treat_output(t_red *red)
{
	if (red->is_double)
	{
		red->fd = open(red->file, O_CREAT | O_APPEND | O_WRONLY, 0644);
		if (red->fd == -1)
		{
			perror("MMSHELL: open");
			return (1);
		}
	}
	else if (!red->is_double)
	{
		red->fd = open(red->file, O_CREAT | O_TRUNC | O_WRONLY, 0644);
		if (red->fd == -1)
		{
			perror("MMSHELL: open");
			return (1);
		}
	}
	if (check_io_dup(red))
	{
		redfunc().remove(0);
	}
}

int	treat_input(t_red *red)
{
	if (check_io_dup(red))
	{
		redfunc().remove(0);
		return (0);
	}
	if (!red->is_double)
		red->fd = open(red->file, O_RDONLY);
	if (red->fd == -1)
	{
		perror("MMSHELL: open");
		return (1);
	}
	return (0);
}

int	check_red(t_red *red)
{
	if (!red->is_output)
		return (treat_input(red));
	if (red->is_output)
		return (treat_output);
}
