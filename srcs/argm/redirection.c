/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 19:43:44 by mgranate          #+#    #+#             */
/*   Updated: 2023/01/17 19:48:49 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	get_redirections(char **split, int i)
{
	t_red	*red;
	int		j;

	j = -1;
	while (split[++j])
	{
		red = get_red(split, red);
	}
	printf("%d\n", i);
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
			get_redirections(split, 1);
		else if (!string().strncmp(split[i], ">>", string().len(split[i], -1)))
	 		get_redirections(split, 2);
		else if (!string().strncmp(split[i], "<", string().len(split[i], -1)))
			get_redirections(split, 3);
		else if (!string().strncmp(split[i], "<<", string().len(split[i], -1)))
			get_redirections(split, 4);
	}
return (0);
}
