/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 17:45:22 by mtavares          #+#    #+#             */
/*   Updated: 2022/11/23 17:04:33 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/builtins.h"

int	is_valid(char *str)
{
	int	i;

	i = -1;
	while (str[++i] && str[i] != '=')
	{
		if (i == 0 && !((str[i] >= 'a' && str[i] <= 'z') || \
		(str[i] >= 'A' && str[i] <= 'Z')))
			return (0);
		if (i && !string().ft_isalnum(str[i]))
			return (0);
	}
	return (1);
}

int	print_error(t_command *cmd, int status, char *str)
{
	write(2, "MMShell: ", 9);
	write(2, cmd->args[0], string().len(cmd->args[0], -1));
	write(2, ": '", 3);
	write(2, cmd->args[1], string().len(cmd->args[1], -1));
	write(2, "'", 1);
	write(2, str, string().len(str, -1));
	return (status);
}
