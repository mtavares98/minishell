/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 16:33:42 by mtavares          #+#    #+#             */
/*   Updated: 2022/11/02 18:20:31 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/execution.h"
#include "../../includes/arguments.h"

int	execution(t_command **cmd, char **envp)
{
	char	*pathenv;

	pathenv = getpath(envp);
	//printlist(*cmd);
	if (check_files((cmd), pathenv + 5))
		return (2);
	//printlist(*cmd);
	/* if (prep_exec(cmd, envp) != 0)
		return (1); */
	return (0);
}
