/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 01:09:18 by mtavares          #+#    #+#             */
/*   Updated: 2022/10/30 01:19:18 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/execution.h"

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
		i = -1;
		while (env->pipe[++i])
		{
			j = -1;
			while (++j < 2)
				if (env->pipe[i][j] != -1)
					close(env->pipe[i][j]);
		}
		alloc().free_matrix((void **)env->pipe);
		env->pipe = NULL;
	}
}

void	close_fd(int *in, int *out)
{
	if (*in)
	{
		close(*in);
		*in = -1;
	}
	if (*out != 1)
	{
		close(*out);
		*out = -1;
	}
}