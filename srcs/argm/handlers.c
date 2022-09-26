/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 23:25:14 by mgranate          #+#    #+#             */
/*   Updated: 2022/09/26 18:05:34 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"


char	*handler_path(char *str)
{
	int		i;
	char	*path;

	i = 0;
	path = NULL;
	while (*str && *str == ' ')
		str++;
	if (*str != '/')
		return (0);
	while (str[i] && (string().ft_isalnum(str[i]) || str[i] == '/'))
		i++;
	path = string().substr(str, 0, i);
	str = str + i;
	return (path);
}

int	count_quotes(char *str, char qt)
{
	int	i;

	i = 0;
	while (*str)
	{
		if (*str == qt)
			return (i);
		str++;
		i++;
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
			i = count_quotes(str + 1, '"');
			str = str + i + 1;
		}
		if (*str == '\'')
		{
			i = count_quotes(str + 1, '\'');
			str = str + i + 1;
		}
		str++;
	}
	return (i);
}

int	argm_handler(char *str)
{
	char			**split;
	char			*path;
	int				i;
	int				j;

	i = 0;
	j = 0;
	path = NULL;
	split = NULL;
	while (str[j])
	{
		if (str[j] == '/')
		{
			path = handler_path(str);
			i = string().len(path, -1);
			break ;
		}
		j++;
	}
	str = str + i;
	if (!validate_string(str))
		return (0);
	printf("STR BEFORE SPLIT == %s\n", str);
	split = ft_split(str, ' ');
	i = -1;
	while (split[++i])
		printf("Split[%d] == %s\n", i, split[i]);
	cmdfunc().add(path, split);
	return (1);
}
