/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 18:44:26 by mtavares          #+#    #+#             */
/*   Updated: 2023/02/01 16:40:07 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	print_error_cmd(int status, char path_exists, char *file)
{
	printf_fd(2, "MMShell: ");
	if (file)
		printf_fd(2, "'%s': ", file);
	else
		printf_fd(2, "'': ");
	if (path_exists)
		printf_fd(2, "command not found\n");
	else
		printf_fd(2, "No such file or directory\n");
	return (status);
}
