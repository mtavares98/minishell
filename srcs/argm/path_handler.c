/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 23:29:03 by mgranate          #+#    #+#             */
/*   Updated: 2022/10/21 23:29:42 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/arguments.h"

char	*handle_split(char *split)
{
	int	sz;

	sz = string().len(split, - 1);
	while (split[--sz] != '/')
		split[sz] = '\0';
	return (split);
}

char	*path_handler2(char * str, char *path)
{
	int	i;
	int	sz;

	i = 1;
	sz = string().len(str, -1);
	while (str[--sz] != '/')
		i++;
	path = string().substr(str, sz + 1, i);
	return (path);
}

char	*handler_path(char *str)
{
	int		i;
	char	*path;

	i = 0;
	path = NULL;
	if (str[i] == '/')
	{
		path = path_handler2(str, path);
		return(path);
	}
	else
		path = string().strdup(str);
	return (path);
}