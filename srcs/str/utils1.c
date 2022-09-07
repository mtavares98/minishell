/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 17:47:33 by mtavares          #+#    #+#             */
/*   Updated: 2022/09/07 21:46:56 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/str.h"

static char	**new_str(char **str, char *s, char *c, int counter)
{
	char	*tmp;
	int		i;

	tmp = NULL;
	i = -1;
	while (*s && ft_strchr(c, *s))
		s++;
	while (s[++i] && !ft_strchr(c, s[i]) && s[i])
		;
	if (!tmp && i > 0)
		tmp = (char *)malloc(i + 1);
	if (tmp)
	{
		str = new_str(str, s + i, c, counter + 1);
		tmp[i] = '\0';
		while (--i > -1)
			tmp[i] = s[i];
	}
	if (!str)
		str = (char **) malloc(sizeof(char *) * (counter + 1));
	if (!str)
		return (NULL);
	str[counter] = tmp;
	return (str);
}

char	**split(char *s, char *c)
{
	char	**str;

	if (!s)
		return (NULL);
	str = new_str(NULL, s, c, 0);
	return (str);
}

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
