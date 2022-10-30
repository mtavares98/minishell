/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 16:33:42 by mtavares          #+#    #+#             */
/*   Updated: 2022/10/30 21:34:51 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/execution.h"
#include "../../includes/arguments.h"

int	execution(t_command **cmd)
{
	char	*pathenv;

	pathenv = getpath(this_env()->env);
	if (check_files((cmd), pathenv + 5))
		return (2);
	if (prep_exec(cmd))
		return (1);
	return (0);
}
