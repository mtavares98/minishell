/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 23:25:14 by mgranate          #+#    #+#             */
/*   Updated: 2022/10/21 23:29:36 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/arguments.h"


int	count_quotes(char *str, char qt)
{
	int	i;

	i = 0;
	printf("%c\n", *str);
	while (*str)
	{
		if (*str == qt)
		{
			i++;
			return (i);
		}
		i++;
		str++;
	}
	return (0);
}

int	validate_string(char * str)
{
	int	i;

	i = 1;
	if (!(*str) || !str[0])
		return (0);
	while (*str)
	{
		if (*str == '"')
		{
			if (!(*str + 1))
				return (0);
			i = count_quotes(str + 1, '"');
			str = str + i;
		}
		if (*str == '\'')
		{
			if (!(*str + 1))
				return (0);
			i = count_quotes(str + 1, '\'');
			str = str + i;
		}
		str++;
	}
	return (i);
}


int	argm_handler(char *str)
{
	char			**split;
	char			*path;

	path = NULL;
	split = NULL;
	if (!validate_string(str))
	{
		printf("Invalid use of quotes\n");
		return (0);
	}
	split = ft_split(str, ' ');
	if (!split || !split[0])
		return (0);
	path = handler_path(split[0]);
	if (split[0][0] == '/')
	{
		split [0] = handle_split(split[0]);
		cmdfunc().add(path, split);
	}
	else
		{
		split++;
		cmdfunc().add(path, split);
		split--;	
		}
	alloc().free_matrix((void **)split);
	alloc().free_array((void *)path);
	return (1);
}
