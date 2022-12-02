/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 19:43:44 by mgranate          #+#    #+#             */
/*   Updated: 2022/12/02 10:34:09 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

//Redirections List, does not handle "|" yet
//Still haven't apllied the clean function. REMINDER

int	get_redirections(char *split, int i)
{
	printf("%d\n", i);
	printf("%s\n", split);
	if (i == 1)
		redfunc().add(split, 0, 1);
	if (i == 2)
		redfunc().add(split, 1, 1);
	if (i == 3)
		redfunc().add(split, 0, 0);	
	if (i == 4)
		redfunc().add(split, 1, 0);
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