/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate_ls <mgranate_ls@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 19:43:44 by mgranate          #+#    #+#             */
/*   Updated: 2023/01/22 04:04:09 by mgranate_ls      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"


int	get_redirections(char *split, int i)
{
	if (i == 1)
		redfunc().add(split, 0, 1, this_red(NULL));
	if (i == 2)
		redfunc().add(split, 1, 1, this_red(NULL));
	if (i == 3)
		redfunc().add(split, 0, 0, this_red(NULL));
	if (i == 4)
		redfunc().add(split, 1, 0, this_red(NULL));
	return (1);
}

int	check_redirection(char **split)
{
	int	i;

    i = -1;
    while (split[++i])
    {
       if (split[i][1] && split[i][0] == '>' && split[i][1] == '>')
            get_redirections(split[i + 1], 2);
       else if (split[i][1] && split[i][0] == '<' && split[i][1] == '<')
           get_redirections(split[i + 1], 4);
       else if (split[i][0] == '>')
            get_redirections(split[i + 1], 1);
       else if (split[i][0] == '<')
            get_redirections(split[i + 1], 3);
    }
return (0);
}