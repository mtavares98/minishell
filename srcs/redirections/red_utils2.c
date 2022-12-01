/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 23:58:35 by mtavares          #+#    #+#             */
/*   Updated: 2022/11/28 00:32:32 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/red_utils.h"

void	remove_by_reference(t_red *remove)
{
	t_red	*tmp;

	tmp = *this_red(NULL);
	if (!tmp || !remove)
		return ;
	if (tmp == remove)
	{
		remove_node_red(remove);
		return ;
	}
	while (tmp->next && tmp->next != remove)
		tmp = tmp->next;
	if (tmp == remove)
	{
		tmp->next = remove->next;
		remove_node_red(remove);
	}
}
