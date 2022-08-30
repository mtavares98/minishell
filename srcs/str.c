/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 15:26:31 by mtavares          #+#    #+#             */
/*   Updated: 2022/08/30 23:35:44 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/str.h"

char	*ft_strrchr(char *str, char c)
{
	int	i;

	i = ft_strlen(str) + 1;
	if (!str)
		return (NULL);
	while (str[--i] != c && i > -1)
		;
	if (i == -1)
		return (NULL);
	return (&str[i]);
}

char	*ft_strchr(char *str, char c)
{
	int	i;

	i = -1;
	if (!str)
		return (NULL);
	while (str[++i] != c && str[i])
		;
	if (!str[i])
		return (NULL);
	return (&str[i]);
}

int	ft_strlen(char *str)
{
	int	len;

	len = -1;
	if (!str)
		return (0);
	while (str[++len])
		;
	return (len);
}

t_str	str(void)
{
	static t_str	str = {ft_strlen, ft_strchr, ft_strrchr, strtrim};

	return (str);
}
