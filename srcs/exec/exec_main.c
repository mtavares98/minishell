/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 16:33:42 by mtavares          #+#    #+#             */
/*   Updated: 2022/10/25 12:32:01 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/execution.h"

int	execution(t_command **cmd, char **envp)
{
	char	*pathenv;

	pathenv = getpath(envp);
	if (check_files((cmd), pathenv + 5))
		return (2);
	if (prep_exec(cmd, envp) != 0)
		return (1);
	return (0);
}
