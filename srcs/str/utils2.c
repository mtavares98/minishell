/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 22:26:25 by mtavares          #+#    #+#             */
/*   Updated: 2022/11/09 00:48:42 by mgranate         ###   ########.fr       */
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
	if (start > (size_t)ft_strlen(s, -1))
		return (alloc().calloc(1));
	if (len > (size_t)ft_strlen(s + start, -1))
		len = ft_strlen(s + start, -1);
	str = alloc().calloc((len + 1));
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
	little_len = ft_strlen(little, -1);
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

/*
	The  strdup()  function returns a pointer to a new string which is a
duplicate of the string s.  Memory for the new string is
       obtained with malloc(3), and can be freed with free(3).
*/

char	*ft_strdup(char *s)
{
	char	*str;
	int		i;

	str = alloc().calloc(string().len(s, -1) + 1);
	if (!str)
		return (NULL);
	i = -1;
	while (s[++i])
		str[i] = s[i];
	str[i] = 0;
	return (str);
}

int	ft_ischar(char c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}
