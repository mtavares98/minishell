/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 23:25:14 by mgranate          #+#    #+#             */
/*   Updated: 2022/10/26 14:34:46 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/arguments.h"


int	count_quotes(char *str, char qt)
{
	int	i;

	i = 0;
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
	path = string().strdup(split[0]);
	if (split[0][0] == '/')
	{
		split [0] = handle_split(split[0]);
		cmdfunc().add(path, split);
	}
	else
		cmdfunc().add(path, split);
	alloc().free_matrix((void **)split);
	alloc().free_array((void *)path);
	return (1);
}
