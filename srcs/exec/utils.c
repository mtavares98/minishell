/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 17:51:10 by mtavares          #+#    #+#             */
/*   Updated: 2022/09/18 23:02:46 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/execution.h"

int	**pipesfd_or_processid(int nbcmd)
{
	int	**pfd;
	int	i;

	if (nbcmd != 0)
		pfd = alloc().calloc(nbcmd, sizeof(int *));
	if (!pfd)
		return (NULL);
	i = -1;
	while (++i < nbcmd)
	{
		pfd[i] = alloc().calloc(nbcmd, sizeof(int));
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

/*
	It will return a complete path for a file based on envp
*/
char	*get_complete_path(char *cmd, char **path)
{
	int		i;
	int		j;
	int		path_size;
	char	*np;

	path_size = string().len(*path, ':');
	np = alloc().calloc(sizeof(char), string().len(cmd, -1) + path_size + 1);
	if (!np)
		return (NULL);
	i = -1 * (path != NULL);
	while (path && *path && ++i < path_size - 1)
		np[i] = *(*path)++;
	if (*path && (**path == ':' || **path != '\0'))
	{
		np[i++] = '/';
		*path += 1;
	}
	j = 0;
	while (cmd && cmd[j])
		np[i++] = cmd[j++];
	return (np);
}
