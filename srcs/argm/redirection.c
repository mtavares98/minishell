/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 19:43:44 by mgranate          #+#    #+#             */
/*   Updated: 2022/11/29 20:41:21 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	get_redirections(char **split)
{
	t_red *red;

	(void)red;
	(void)split;
	return (-1);
}

int	check_redirection(char **split)
{
	int	i;

	i = -1;
	while (split[++i])
	{
		if (!string().strncmp(split[i], ">", string().len(split[i], -1)))
			i = get_redirections(split);
		else if (!string().strncmp(split[i], ">>", string().len(split[i], -1)))
			i = get_redirections(split);
		else if (!string().strncmp(split[i], "<", string().len(split[i], -1)))
			i = get_redirections(split);
		else if (!string().strncmp(split[i], "<<", string().len(split[i], -1)))
			i = get_redirections(split);
		if (i == -1)
			return (1);
	}
return (0);
}