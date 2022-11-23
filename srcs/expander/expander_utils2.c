/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 00:36:57 by mgranate          #+#    #+#             */
/*   Updated: 2022/11/23 00:56:52 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/expander.h"

static int	ft_int_lenght(long n)
{
	if (n < 10 && n > -10)
		return (1);
	else
		return (1 + ft_int_lenght(n / 10));
}

char	*ft_itoa(int n)
{
	char	*trn;
	int		len;
	int		i;
	int		nb;

	nb = n;
	trn = 0;
	len = ft_int_lenght(n) + 1 + (n < 0);
	trn = (char *)malloc(sizeof(char) * (len));
	if (!trn)
		return (NULL);
	trn[len - 1] = '\0';
	i = len -2;
	while (i >= 0)
	{
		trn[i] = (n % 10) * ((n > 0) - (n < 0)) + '0';
		n /= 10;
		i--;
	}
	if (nb < 0)
		trn[0] = '-';
	return (trn);
}

char	*pid_switch(char *str)
{
	char	*tmp;
	char	*pid;
	int		pd;
	int		i;

	pd = getpid();
	pid = ft_itoa(pd);
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
	
	ch = ft_itoa(this_env()->status);
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
	return (str);
}
