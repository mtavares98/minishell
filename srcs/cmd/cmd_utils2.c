/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate_ls <mgranate_ls@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 15:24:59 by mgranate          #+#    #+#             */
/*   Updated: 2023/01/25 01:10:30 by mgranate_ls      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cmd_utils.h"

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

char	**argms_node(char **args, char **split)
{
	int	i;

	i = -1;
	args = alloc().calloc((list_size(split, "-1") + 1) * sizeof(char **));
	while (split[++i])
		args[i] = string().strdup(split[i]);
	return (args);
}

t_command	*new_node(char *path, char **split)
{
	t_command	*node;

	node = alloc().calloc(sizeof(t_command));
	if (!node)
		return (NULL);
	node->path = path;
	node->args = split;
	node->infd = -1;
	node->outfd = -1;
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
