/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 17:47:33 by mtavares          #+#    #+#             */
/*   Updated: 2022/09/10 00:30:42 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/str.h"

/*
	This function evaluates if a char is space
*/

int	is_space(char c)
{
	return ((c > 8 && c < 14) || c == 32);
}

/*
	This function helps the split to do the work
*/

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

/*
	This function returns a matriz of string with a string as delimiters
*/

char	**split(char *s, char *c)
{
	char	**str;

	if (!s)
		return (NULL);
	str = new_str(NULL, s, c, 0);
	return (str);
}

/*
	Returns a string without delimiters (the string set)
		at the beguining and the end
*/

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

/*
	Converts a string in to a number.
	See later for improvement because it return a long int
*/

long	_atoi(char *str)
{
	long	n;
	long	sig;
	int		i;

	n = 0;
	i = -1;
	sig = 1;
	if (!str || !str[0] || !ft_strncmp(str, "-", 2) \
	|| !ft_strncmp(str, "+", 2))
		return (2147483648);
	while (is_space(str[++i]))
		;
	if (str[i] == '-' || str[i] == '+')
		sig = (str[i] != '-') - (str[i++] == '-');
	while (is_dig(str[i]))
	{
		n = n * 10 + sig * (str[i++] - '0');
		if (n == INT_MAX || n == INT_MIN)
			return (2147483648);
	}
	if (!is_space(str[i]) && str[i])
		return (2147483648);
	return (n);
}
