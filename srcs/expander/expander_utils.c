/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 19:06:40 by mgranate          #+#    #+#             */
/*   Updated: 2023/01/31 14:11:28 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

int	ft_strcpy(char *tmp, char *str, char c)
{
	int	i;

	i = -1;
	if (!tmp && !tmp[0])
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
		if (str[i] == '$' && str[i + 1] == '$')
			i += 2;
		if (str[i] == '$' && j == 0)
			while (++j && str[++i] && string().ft_isalnum(str[i]))
				;
		if (!str[i])
			break ;
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
