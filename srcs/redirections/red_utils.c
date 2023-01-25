/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 17:49:36 by mtavares          #+#    #+#             */
/*   Updated: 2023/01/25 22:25:08 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <red_utils.h>

void	remove_node_red(t_red *node)
{
	if (!node)
		return ;
	if (node->file)
		alloc().free_array(node->file);
	alloc().free_array(node);
}

void	red_remove(int i, t_red **begin)
{
	t_red	*rem;
	t_red	*tmp;
	int		j;

	if (!*begin)
		return ;
	if (i < 0)
		return ;
	if (i == 0)
	{
		rem = *begin;
		*begin = (*begin)->next;
	}
	else
	{
		tmp = *begin;
		j = 0;
		while (++j < i && tmp->next)
			tmp = tmp->next;
		rem = tmp->next;
		tmp->next = rem->next;
	}
	remove_node_red(rem);
}

t_red	*red_get(int i, t_red *red)
{
	int		j;

	if (!red && i < 0)
		return (NULL);
	j = -1;
	while (++j < i && red)
		red = red->next;
	return (red);
}

t_red	*new_node_red(char *file, int is_double, int is_output)
{
	t_red	*node;

	node = alloc().calloc(sizeof(t_red));
	if (!node)
		return (NULL);
	node->fd = -1;
	node->file = file;
	node->is_double = is_double;
	node->is_output = is_output;
	node->next = NULL;
	return (node);
}

t_red	*red_add(char *file, int is_double, int is_output, t_red **begin)
{
	t_red	*new;
	t_red	*tmp;

	tmp = NULL;
	new = new_node_red(file, is_double, is_output);
	if (!new)
		return (NULL);
	if (!*begin)
	{
		*begin = new;
		return (new);
	}
	tmp = *begin;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	return (new);
}
