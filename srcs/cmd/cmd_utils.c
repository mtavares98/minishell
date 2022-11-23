/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 21:11:33 by mtavares          #+#    #+#             */
/*   Updated: 2022/11/23 14:44:18 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cmd_utils.h"
#include <stdio.h>

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
	node->next = NULL;
	return (node);
}

t_command	*cmdadd(char *path, char **split)
{
	t_command	*new;
	t_command	**cmd;
	t_command	*tmp;

	tmp = NULL;
	new = new_node(path, split);
	if (!new)
		return (NULL);
	cmd = this();
	if (!*cmd)
	{
		*cmd = new;
		return (new);
	}
	tmp = *cmd;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	return (new);
}

t_command	*cmdget(int i)
{
	t_command	*cmd;
	int			j;

	cmd = (*this());
	if (!cmd && i < 0)
		return (NULL);
	j = -1;
	while (++j < i && cmd)
		cmd = cmd->next;
	return (cmd);
}

void	remove_node(t_command *node)
{
	if (node->path)
		alloc().free_array(node->path);
	if (node->args)
		alloc().free_matrix((void *)node->args);
	if (node)
		alloc().free_array(node);
}

void	cmdremove(int i)
{
	t_command	*rem;
	t_command	*tmp;
	t_command	**cmd;
	int			j;

	cmd = this();
	if (i < 0)
		return ;
	if (i == 0)
	{
		rem = *cmd;
		*cmd = (*cmd)->next;
	}
	else
	{
		tmp = *cmd;
		j = 0;
		while (++j < i && tmp->next)
			tmp = tmp->next;
		rem = tmp->next;
		tmp->next = rem->next;
	}
	remove_node(rem);
}
