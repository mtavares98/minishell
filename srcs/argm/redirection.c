/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 19:43:44 by mgranate          #+#    #+#             */
/*   Updated: 2023/01/06 16:41:41 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

//Redirections List, does not handle "|" yet
//Still haven't apllied the clean function. REMINDER

/*
	while (cmd)
	{
		this_red(cmd->io);
		
	}
*/

int	get_redirections(char *split, int i)
{
	printf("%d\n", i);
	printf("%s\n", split);
	if (i == 1)
		redfunc().add(split, 0, 1, this_red(NULL));
	if (i == 2)
		(redfunc()).add(split, 1, 1, this_red(NULL));
	if (i == 3)
		(redfunc()).add(split, 0, 0, this_red(NULL));
	if (i == 4)
		(redfunc()).add(split, 1, 0, this_red(NULL));
	return (1);
}

int	check_redirection(char **split)
{
	int	i;

	i = -1;
	while (split[++i])
	{
		if (!string().strncmp(split[i], ">", string().len(split[i], -1)))
			get_redirections(split[i - 1], 1);
		else if (!string().strncmp(split[i - 1], ">>", string().len(split[i], -1)))
			get_redirections(split[i], 2);
		else if (!string().strncmp(split[i - 1], "<", string().len(split[i], -1)))
			get_redirections(split[i], 3);
		else if (!string().strncmp(split[i - 1], "<<", string().len(split[i], -1)))
			get_redirections(split[i], 4);
	}
return (0);
}
