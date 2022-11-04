/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 01:09:18 by mtavares          #+#    #+#             */
/*   Updated: 2022/11/03 09:57:19 by mgranate         ###   ########.fr       */
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

/* int	get_cmd_not_builtin(t_command *cmd)
{
	int	len;

	len = 0;
	if (!cmd)
		return (0);
	while (cmd)
	{
		if (!is_builtin(cmd->path))
			len++;
		cmd = cmd->next;
	}
	return (len);
} */

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
