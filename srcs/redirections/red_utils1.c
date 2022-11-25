/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_utils1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 17:49:36 by mtavares          #+#    #+#             */
/*   Updated: 2022/11/25 18:08:08 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/red_utils.h"

static void	remove_node(t_red *node)
{
	if (!node)
		return (NULL);
	if (node->file)
		alloc().free_array(node->file);
	alloc().free_array(node);
}

void	redremove(int i)
{
	t_red	*rem;
	t_red	*tmp;
	t_red	**red;
	int		j;

	red = this();
	if (i < 0)
		return ;
	if (i == 0)
	{
		rem = *red;
		*red = (*red)->next;
	}
	else
	{
		tmp = *red;
		j = 0;
		while (++j < i && tmp->next)
			tmp = tmp->next;
		rem = tmp->next;
		tmp->next = rem->next;
	}
	remove_node(rem);
}

t_red	*redget(int i)
{
	t_red	*red;
	int		j;

	red = (*this_red());
	if (!red && i < 0)
		return (NULL);
	j = -1;
	while (++j < i && red)
		red = red->next;
	return (red);
}

t_red	*redadd(char *file, int is_double, int is_output)
{
	t_red	*new;
	t_red	**red;
	t_red	*tmp;

	tmp = NULL;
	new = new_node(file, is_double, is_output);
	if (!new)
		return (NULL);
	red = this();
	if (!*red)
	{
		*red = new;
		return (new);
	}
	tmp = *red;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	return (new);
}
