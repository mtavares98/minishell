/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 23:25:14 by mgranate          #+#    #+#             */
/*   Updated: 2022/10/16 15:27:24 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*path_handler2(char * str, char *path)
{
	int	i;

	i = 0;
	while (*str != '/')
		str++;
	while (str[i] && (string().ft_isalnum(str[i]) || str[i] == '/'))
		i++;
	path = string().substr(str, 0, i);
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
	while (str[i])
	{
		if (str[i] == '/' && string().ft_isspace(str[i - 1]))
		{
			path = path_handler2(str, path);
			return (path);
		}
		i++;
	}
	return (NULL);
}

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
	path = handler_path(str);
	if (path)
		str = get_substring(str, '/');
	split = ft_split(str, ' ');
	cmdfunc().add(path, split);
	alloc().free_matrix((void *)split);
	alloc().free_array((void *)path);
	return (1);
}
