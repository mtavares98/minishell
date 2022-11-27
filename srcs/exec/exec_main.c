/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 16:33:42 by mtavares          #+#    #+#             */
/*   Updated: 2022/11/27 19:01:13 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/execution.h"

int	prep_red(t_command **cmd)
{
	t_command	*tmp;
	t_red		*head;

	tmp = *cmd;
	while (tmp)
	{
		if (prep_heredoc(tmp->io))
			return (1);
		tmp = tmp->next;
	}
	tmp = *cmd;
	head = tmp->io;
	(void)head;
	return (0);
}

int	execution(t_command **cmd)
{
	char	*pathenv;

	if (prep_red(cmd))
		return (1);
	pathenv = getpath(this_env()->env);
	if (check_files((cmd), pathenv + 5 * (pathenv != NULL)))
	{
		free_memory(cmd, this_env());
		return (2);
	}
	if (prep_exec(cmd))
		return (1);
	return (0);
}
