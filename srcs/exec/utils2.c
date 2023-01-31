/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 01:09:18 by mtavares          #+#    #+#             */
/*   Updated: 2023/01/31 14:11:22 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

void	update_status(t_env *env)
{
	int	status;

	if (WIFEXITED(env->status))
	{
		status = WEXITSTATUS(env->status);
		env->status = status;
	}
}

void	free_memory(t_command **cmd)
{
	if (cmd)
	{
		while (*cmd)
			(cmdfunc()).remove(0);
	}
}

void	close_fd_exeption(t_command **cmd, int in, int out)
{
	t_command	*tmp;

	if (!*cmd)
		return ;
	tmp = *cmd;
	while (tmp)
	{
		if (tmp->infd != 0 && tmp->infd != -1 && tmp->infd != in)
		{
			close(tmp->infd);
			tmp->infd = -1;
		}
		if (tmp->outfd != 1 && tmp->outfd != -1 && tmp->outfd != out)
		{
			close(tmp->outfd);
			tmp->outfd = -1;
		}
		tmp = tmp->next;
	}
}

void	close_fd(int *in, int *out)
{
	if (*in && *in != -1)
	{
		close(*in);
		*in = -1;
	}
	if (*out != 1 && *out != -1)
	{
		close(*out);
		*out = -1;
	}
}
