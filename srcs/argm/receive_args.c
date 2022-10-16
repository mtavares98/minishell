/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   receive_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 16:52:55 by mgranate          #+#    #+#             */
/*   Updated: 2022/10/01 18:39:05 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	receive_args(char *str)
{
	t_command	*cmd;

	argm_handler(str);
	cmd = *this();
	printlist(*this());
	while (cmd)
	{
		cmd = cmd->next;
		cmdfunc().remove(0);
	}
	return (1);
}
