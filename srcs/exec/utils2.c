/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 01:09:18 by mtavares          #+#    #+#             */
/*   Updated: 2022/10/29 20:33:45 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/execution.h"

void	free_memory(t_command **cmd, t_env *env)
{
	int	i;
	int	j;

	while (*cmd)
		cmdfunc().remove(0);
	alloc().free_matrix((void **)this_env()->env);
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

void	name2(int out, t_command **cmd)
{
	int	status;

	status = exec_builtins(out, cmd);
	exit(status);
}
