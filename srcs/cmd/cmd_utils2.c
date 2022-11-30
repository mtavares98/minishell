/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 15:24:59 by mgranate          #+#    #+#             */
/*   Updated: 2022/11/30 15:09:19 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cmd_utils.h"

/* int	list_size(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	return (i);
} */

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
