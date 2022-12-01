/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 15:24:59 by mgranate          #+#    #+#             */
/*   Updated: 2022/12/01 12:33:03 by mtavares         ###   ########.fr       */
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
	args = alloc().calloc((list_size(split) + 1) * sizeof(char **));
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
	if (path)
		node->path = path_node(path, node->path);
	if (split)
		node->args = argms_node(node->args, split);
	node->infd = -1;
	node->outfd = -1;
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
