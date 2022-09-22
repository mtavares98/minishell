/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 21:10:14 by mtavares          #+#    #+#             */
/*   Updated: 2022/09/21 16:44:12 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cmd_utils.h"

t_command	**this(t_command **cmd)
{
	return (cmd);
}

t_command	**command(void)
{
	static t_command	*cmd;

	return (&cmd);
}

t_cmdfunc	cmdfunc(void)
{
	static t_cmdfunc	funcs = {
		cmdadd, cmdget, cmdremove
	};

	return (funcs);
}
