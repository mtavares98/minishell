/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 19:06:40 by mgranate          #+#    #+#             */
/*   Updated: 2022/11/19 02:56:22 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/expander.h"

int	ft_strcpy(char *tmp, char *str, char c)
{
	int	i;
	
	i = -1;
	if (!tmp[0] && !tmp)
		return (0);
	while (tmp[++i])
	{
		if (tmp[i] == c)
			break ;
		str[i] = tmp[i];
	}
	str[i] = 0;
	return (i);
}

int	check_alloc_size(char *str, char *env)
{
	int	i;
	int	ct;
	int	j;

	j = 0;
	i = -1;
	ct = 0;
	while (str[++i])
	{
		if (str[i] == '$' && j == 0)
		{
			while (str[++i] && string().ft_isalnum(str[i]))
				;
			j = 1;
		}
		if (!str[i])
			break ;
		ct++;
	}
	i = -1;
	while (env[++i])
	{
		if (env[i] == '=')
			while (env[++i])
				ct++;
		if (!env[i])
			break ;	
	}
	return (ct);
}

int	check_single_quote(char *split, int i)
{
	while (split[++i] && split[i] != '\'')
		;
	return (i);
}