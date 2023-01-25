/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 23:58:35 by mtavares          #+#    #+#             */
/*   Updated: 2023/01/25 22:25:41 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <red_utils.h>

void	remove_by_reference(t_red *remove, t_red **begin)
{
	t_red	*tmp;

	tmp = *begin;
	if (!tmp || !remove)
		return ;
	if (*begin == remove)
		*begin = (*begin)->next;
	else
	{
		tmp = *begin;
		while (tmp->next && remove != tmp->next)
			tmp = tmp->next;
		tmp->next = remove->next;
	}
	remove_node_red(remove);
}
