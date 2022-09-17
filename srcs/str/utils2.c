/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 22:26:25 by mtavares          #+#    #+#             */
/*   Updated: 2022/09/17 14:35:01 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/string_utils.h"

/*
	Allocates (with malloc(3)) and returns a substring
from the string ’s’.
The substring begins at index ’start’ and is of
maximum size ’len’.
*/

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (!s)
		return (NULL);
	if (start > (size_t)ft_strlen(s))
		return (alloc().calloc(1, sizeof(char)));
	if (len > (size_t)ft_strlen(s + start))
		len = ft_strlen(s + start);
	str = alloc().calloc((len + 1), sizeof(char));
	if (!str)
		return (NULL);
	i = -1;
	while (++i < len)
		str[i] = s[start + i];
	str[i] = 0;
	return (str);
}

/*
	The strnstr() function locates the first occurrence of the
null-terminated string little in the string big, where not more than
len characters are searched.
Characters that appear after a ‘\0’ characterare not searched.
*/
char	*ft_strnstr(char *big, char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	little_len;

	if (!*little)
		return ((char *)big);
	if (len == 0)
		return (NULL);
	i = -1;
	little_len = ft_strlen(little);
	while (big[++i])
	{
		j = -1;
		while (++j + i < len && big[i + j] && \
		little[j] && big[i + j] == little[j])
			;
		if (j == little_len)
			return ((char *)(big + i));
	}
	return (NULL);
}

/*
	It compares if a char c is alphanumeric
*/

int	ft_isalnum(char c)
{
	return ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') \
	|| (c >= 'A' && c <= 'Z'));
}
