/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 00:36:57 by mgranate          #+#    #+#             */
/*   Updated: 2022/11/27 18:28:17 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <expander.h>

char	*remove_exp(char *str)
{
	char	*tmp;
	int		i;

	tmp = str;
	i = 0;
	i = check_alloc_size(str, NULL, -1);
	str = alloc().calloc(i + 1);
	if (!str)
	{
		str = tmp;
		return (str);
	}
	i = ft_strcpy(tmp, str, '$');
	if (tmp[i] == '$' && tmp[i + 1] == '$')
		i += 1;
	while (tmp[++i] && string().ft_isalnum(tmp[i]))
		;
	if (tmp[i])
		ft_strcpy(tmp + i, str + string().len(str, -1), -1);
	alloc().free_array(tmp);
	return (str);
}

char	*get_status(char *str)
{
	char	*ch;
	char	*tmp;
	int		i;

	i = 0;
	ch = string().itoa(NULL, &i, 1, this_env()->status);
	tmp = str;
	str = alloc().calloc(string().len(tmp, -1) + string().len(ch, -1) + 1);
	if (!str)
	{
		str = tmp;
		return (str);
	}
	i = ft_strcpy(tmp, str, '$');
	ft_strcpy(ch, str + string().len(str, -1), -1);
	i = i + string().len(ch, -1) + 1;
	ft_strcpy(tmp + i, str + string().len(str, -1), -1);
	alloc().free_array(ch);
	alloc().free_array(tmp);
	return (str);
}
