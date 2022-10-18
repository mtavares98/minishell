/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 16:33:42 by mtavares          #+#    #+#             */
/*   Updated: 2022/10/18 22:34:10 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/execution.h"

int	execution(t_command **cmd, char **envp)
{
	char	*pathenv;

	pathenv = getpath(envp);
	if (check_files((cmd), pathenv + 5))
		return (2);
	printf("%s\n", cmdfunc().get(0)->path);
	printf("%s\n", cmdfunc().get(1)->path);
	cmdfunc().remove(0);
	cmdfunc().remove(0);
	return (0);
}
