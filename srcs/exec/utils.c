/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 17:51:10 by mtavares          #+#    #+#             */
/*   Updated: 2022/10/25 14:12:58 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/execution.h"

int	**get_pipesfd(int num_cmd)
{
	int	i;
	int	**pipe_fd;

	pipe_fd = alloc().calloc((num_cmd - 1) * sizeof(int *));
	if (!pipe_fd)
		return (NULL);
	i = -1;
	while (++i < num_cmd - 1)
	{
		pipe_fd[i] = alloc().calloc(2 * sizeof(int));
		if (!pipe_fd[i])
		{
			alloc().free_matrix((void **)pipe_fd);
			return (NULL);
		}
	}
	return (pipe_fd);
}

char	*getpath(char **envp)
{
	char	*path;
	int		i;

	i = -1;
	path = NULL;
	while (envp[++i])
	{
		if (!string().strncmp(envp[i], "PATH=", 5))
		{
			path = envp[i];
			break ;
		}
	}
	return (path);
}
