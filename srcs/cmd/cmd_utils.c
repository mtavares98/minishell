/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 21:11:33 by mtavares          #+#    #+#             */
/*   Updated: 2022/11/25 17:48:26 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cmd_utils.h"

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
