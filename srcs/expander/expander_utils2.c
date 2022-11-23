/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 00:36:57 by mgranate          #+#    #+#             */
/*   Updated: 2022/11/23 17:36:50 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/expander.h"

char	*pid_switch(char *str)
{
	char	*tmp;
	char	*pid;
	int		pd;
	int		i;

	i = 0;
	pd = getpid();
	pid = string().itoa(NULL, &i, 1, pd);
	pd = string().len(str, -1) + string().len(pid, -1) - 1;
	tmp = str;
	str = alloc().calloc(pd);
	if (!str)
	{
		str = tmp;
		return (str);
	}
	pd = ft_strcpy(tmp, str, '$');
	pd = pd + ft_strcpy(pid, str + pd, -1);
	i = string().len(tmp, '$') + 1;
	ft_strcpy(tmp + i, str + pd, -1);
	alloc().free_array(tmp);
	alloc().free_array(pid);
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
	str = alloc().calloc(string().len(tmp, -1));
	if (!str)
	{
		str = tmp;
		return (str);
	}
	i = ft_strcpy(tmp, str, '$');
	str[i] = ch[0];
	i = i + 2;
	if (tmp + i)
		ft_strcpy(tmp + i, str + string().len(str, -1), -1);
	alloc().free_array(ch);
	alloc().free_array(tmp);
	return (str);
}
