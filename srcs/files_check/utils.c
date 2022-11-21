/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 18:44:26 by mtavares          #+#    #+#             */
/*   Updated: 2022/11/21 19:02:11 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	print_error_cmd(t_command *cmd, int status, char path_exists)
{
	if (!path_exists)
		write(2, "MMShell: ", 9);
	write(2, cmd->args[0], string().len(cmd->args[0], -1));
	if (path_exists)
		write(2, ": command not found\n", 20);
	else
		write(2, ": No such file or directory\n", 28);
	return (status);
}
