/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 15:24:59 by mgranate          #+#    #+#             */
/*   Updated: 2023/01/31 14:04:59 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd_utils.h"

char	*path_node(char	*path, char *new_path)
{
	int	i;

	i = 0;
	new_path = alloc().calloc((string().len(path, -1)) * sizeof(char *));
	if (!new_path)
		return (NULL);
	while (path[i])
	{
		new_path[i] = path[i];
		i++;
	}
	return (new_path);
}

t_command	*new_node(char *path, char **split)
{
	t_command	*node;

	node = alloc().calloc(sizeof(t_command));
	if (!node)
		return (NULL);
	node->path = path;
	node->args = split;
	node->infd = 0;
	node->outfd = 1;
	node->io = NULL;
	node->next = NULL;
	return (node);
}

int	list_size_cmd(void)
{
	t_command	*cmd;
	int			len;

	cmd = *this();
	len = -1;
	while (cmd && ++len)
		cmd = cmd->next;
	return (len);
}
