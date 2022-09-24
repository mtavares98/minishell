/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 21:11:33 by mtavares          #+#    #+#             */
/*   Updated: 2022/09/24 10:57:15 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cmd_utils.h"

t_command	*new_node(char *path, t_tmp *argms)
{
	int			i;
	t_command	*node;

	node = alloc().calloc(sizeof(t_command));
	if (!node)
		return (NULL);
	if (path)
	{
		node->path = alloc().calloc(string().len(path, -1) + 1);
		if (!node->path)
			return (0);
		node->path = path;
	}
	if (argms)
	{
		i = list_size(argms);
		node->args = alloc().calloc((i + 1) * sizeof(char *));
		if (!node->args)
			return (0);
		while (--i >= 0)
		{
			node->args[i] = alloc().calloc(string().len(argms->args, -1) + 1);
			if (!(node->args[i]))
				return (0);
			node->args[i] = argms->args;
			argms = argms->next;
		}
	}
	node->ready = 0;
	node->next = NULL;
	return (node);
}

t_command	*cmdadd(char *path, t_tmp *args)
{
	t_command	*new;
	t_command	**cmd;
	t_command	*tmp;

	new = new_node(path, args);
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
