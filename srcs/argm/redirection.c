/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 19:43:44 by mgranate          #+#    #+#             */
/*   Updated: 2023/01/23 16:55:46 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"


int	get_redirections(char *split, int i)
{
	 char *file;

	 file = string().strdup(split);
	 if (!file)
		  return 1;
	if (i == 1)
		redfunc().add(file, 0, 1, this_red(NULL));
	if (i == 2)
		redfunc().add(file, 1, 1, this_red(NULL));
	if (i == 3)
		redfunc().add(file, 0, 0, this_red(NULL));
	if (i == 4)
		redfunc().add(file, 1, 0, this_red(NULL));
	return (1);
}

int	check_redirection(char **split, t_command *cmd)
{
	int	i;

	 i = -1;
	 this_red(cmd->io);
	 if (split[i][1] && split[i][0] == '>' && split[i][1] == '>')
		  get_redirections(split[i + 1], 2);
	 else if (split[i][1] && split[i][0] == '<' && split[i][1] == '<')
		  get_redirections(split[i + 1], 4);
	 else if (split[i][0] == '>')
		  get_redirections(split[i + 1], 1);
	 else if (split[i][0] == '<')
		  get_redirections(split[i + 1], 3);
	return (0);
}