/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 18:50:29 by mgranate          #+#    #+#             */
/*   Updated: 2023/01/31 14:03:16 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	list_size(char **split, char *c)
{
	int	i;

	i = -1;
	while (split[++i])
	{
		if (string().strchr(c, split[i][0]))
			return (i);
	}
	return (i);
}
