/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 15:24:59 by mgranate          #+#    #+#             */
/*   Updated: 2022/10/21 16:22:59 by mtavares         ###   ########.fr       */
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
