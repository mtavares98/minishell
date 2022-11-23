/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 19:06:40 by mgranate          #+#    #+#             */
/*   Updated: 2022/11/23 18:48:43 by mgranate         ###   ########.fr       */
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
		if (tmp[i] == '\'')
		{
			str[i] = tmp[i];
			while (tmp[++i] && tmp[i] != '\'')
				str[i] = tmp[i];
		}
		if (tmp[i] == c)
			break ;
		str[i] = tmp[i];
	}
	str[i] = 0;
	return (i);
}

int	check_alloc_size_aux(char *env, int ctr, int ct)
{
	if (ctr == 1)
	{
		while (*env && *env != '=')
			env++;
		ct = ct + string().len(++(env), -1);
	}
	return (ct);
}

int	check_alloc_size(char *str, char *env, int ctr)
{
	int	ct;
	int	i;
	int	j;

	i = -1;
	ct = 0;
	j = 0;
	while (str[++i])
	{
		if (str[i] == '\'' && ct++)
			while (str[++i] && str[i] != '\'')
				ct++;
		if (str[i] == '$' && j == 0)
			while (++j && str[++i] && string().ft_isalnum(str[i]))
				;
		if (!str[i])
			break;
		ct++;
	}
	ct = check_alloc_size_aux(env, ctr, ct);
	return (ct);
}

int	check_single_quote(char *split, int i, char c)
{
	while (split[++i] && split[i] != c)
		;
	return (i);
}

int	check_dollar_sign(char *split)
{
	int	i;

	i = -1;
	while (split[++i])
	{
		if (split[i] == '\'')
			i = i + check_single_quote(split, i, '$');
		if (split[i] == '$')
			return (1);
	}
	return (0);
}
