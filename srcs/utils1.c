/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 17:47:33 by mtavares          #+#    #+#             */
/*   Updated: 2022/08/30 23:35:39 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/str.h"

char	*strtrim(char *s1, char *set)
{
	char	*str;
	size_t	i;
	size_t	start;
	size_t	end;

	start = -1;
	end = ft_strlen(s1) + 1;
	if (!s1 || !set)
		return (NULL);
	while (s1[++start] && ft_strchr(set, s1[start]))
		;
	while (s1[--end] && ft_strchr(set, s1[end]))
		;
	str = malloc(sizeof(char) * (end - start + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (start < end)
		str[i++] = s1[start++];
	str[i] = 0;
	return (str);
}
