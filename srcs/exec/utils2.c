/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 01:09:18 by mtavares          #+#    #+#             */
/*   Updated: 2022/11/21 20:01:13 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/execution.h"

void	update_status(t_env *env)
{
	int	status;

	if (WIFEXITED(env->status))
	{
		status = WEXITSTATUS(env->status);
		env->status = status;
	}
}

void	free_memory(t_command **cmd, t_env *env)
{
	int	i;
	int	j;

	if (cmd)
	{
		while (*cmd)
			cmdfunc().remove(0);
	}
	if (env->pipe)
	{
		i = 0;
		while (env->pipe[i])
		{
			j = -1;
			while (++j < 2)
				if (env->pipe[i][j] != -1)
					close(env->pipe[i][j]);
			i++;
		}
		alloc().free_matrix((void **)env->pipe);
		env->pipe = NULL;
	}
}

void	close_fd_exeption(t_env *env, int in, int out)
{
	int	i;
	int	j;

	i = -1;
	if (!env->pipe)
		return ;
	while (env->pipe[++i])
	{
		j = -1;
		while (++j < 2)
		{
			if (env->pipe[i][j] != in && env->pipe[i][j] != out \
			&& env->pipe[i][j] != -1)
			{
				close(env->pipe[i][j]);
				env->pipe[i][j] = -1;
			}
		}
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
