/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 17:51:10 by mtavares          #+#    #+#             */
/*   Updated: 2022/09/20 18:08:13 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/execution.h"

int	**pipesfd_or_processid(int nbcmd)
{
	int	**pfd;
	int	i;

	if (nbcmd != 0)
		pfd = alloc().calloc(nbcmd * sizeof(int *));
	if (!pfd)
		return (NULL);
	i = -1;
	while (++i < nbcmd)
	{
		pfd[i] = alloc().calloc(nbcmd * sizeof(int));
		if (pfd[i])
			return (NULL);
	}
	return (pfd);
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
