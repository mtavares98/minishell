/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_aux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate_ls <mgranate_ls@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 04:06:17 by mgranate_ls       #+#    #+#             */
/*   Updated: 2023/01/22 04:11:25 by mgranate_ls      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	skip_quotes(char *s, char c)
{
	int	i;

	i = 0;
    while (s[i] && s[i] != c)
        i++;
    return (i + 1);
}

int check_reds(char *s)
{
    if (s[1] && (s[0] == '>' && s[1] == '>'))
        return(2);
    else if (s[1] && (s[0] == '<' && s[1] == '<'))
    	return(2);
    return(1);
}

void	splitcpy(char *dst, char *src, int sz)
{
	int	i;

	i = 0;
	while (sz > 0)
	{
		dst[i] = src[i];
		i++;
		sz--;
	}
	dst[i] = 0;
}