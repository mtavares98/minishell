/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 01:09:18 by mtavares          #+#    #+#             */
/*   Updated: 2022/10/29 02:58:16 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/execution.h"

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
	int	i;
	int	j;

	status = exec_builtins(out, *cmd);
	while (*cmd)
		cmdfunc().remove(0);
	alloc().free_matrix((void **)this_env()->env);
	i = -1;
	while (this_env()->pipe[++i])
	{
		j = -1;
		while (++j < 2)
			if (this_env()->pipe[i][j] != -1)
				close(this_env()->pipe[i][j]);
	}
	alloc().free_matrix((void **)this_env()->pipe);
	exit(status);
}
