/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 23:25:14 by mgranate          #+#    #+#             */
/*   Updated: 2022/11/23 14:46:53 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*handle_split(char *split)
{
	int		sz;
	char	*tmp;
	int		i;

	i = 0;
	sz = string().len(split, - 1);
	while (split[--sz] != '/')
		i++;
	tmp = string().substr(split, sz + 1, i);
	while (split[++i])
		split[i] = '\0';
	alloc().free_array(split);
	return (tmp);
}


int	argm_handler(char *str)
{
	char			**split;
	char			*path;

	split = ft_split(str, ' ');
	if (!split || !split[0])
		return (0);
	check_expander(split, this_env());
	path = string().strdup(split[0]);
	if (split[0][0] == '/')
		split [0] = handle_split(split[0]);
	cmdfunc().add(path, split);
	alloc().free_matrix((void **)split);
	alloc().free_array((void *)path);
	return (1);
}
