/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 17:45:22 by mtavares          #+#    #+#             */
/*   Updated: 2022/11/13 17:58:55 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/builtins.h"

int	print_error(t_command *cmd, int status, char *str)
{
	write(2, "MMShell: ", 9);
	write(2, cmd->args[0], string().len(cmd->args[0], -1));
	write(2, ": ", 2);
	write(2, cmd->args[1], string().len(cmd->args[1], -1));
	write(2, str, string().len(str, -1));
	return (status);
}
