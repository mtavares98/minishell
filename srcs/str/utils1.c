/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 17:47:33 by mtavares          #+#    #+#             */
/*   Updated: 2023/01/31 14:14:21 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_utils.h"

/*
	This function evaluates if a char is space
*/

int	ft_isspace(char c)
{
	return ((c > 8 && c < 14) || c == 32);
}

/*
	Returns a string without delimiters (the string set)
		at the beginning and the end
*/

char	*strtrim(char *s1, char *set)
{
	char	*str;
	size_t	i;
	size_t	start;
	size_t	end;

	start = -1;
	end = ft_strlen(s1, -1) + 1;
	if (!s1 || !set)
		return (NULL);
	while (s1[++start] && string().strchr(set, s1[start]))
		;
	while (s1[--end] && string().strchr(set, s1[end]))
		;
	str = alloc().calloc(end - start + 1);
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
	See later for improvement because it returns a long int
*/

long	_atoi(char *s)
{
	long	n;
	long	sig;
	int		i;

	n = 0;
	i = -1;
	sig = 1;
	while (ft_isspace(s[++i]))
		;
	if (s[i] == '-' || s[i] == '+')
	{
		sig = (s[i] != '-') - (s[i] == '-');
		i++;
	}
	while (isdig(s[i]))
		n = n * 10 + sig * (s[i++] - '0');
	while (ft_isspace(s[i]))
		i++;
	return (n);
}

/*
	Itoa converts a number into a string the counter start at 1 because you
		 will always 1 digit
*/

char	*itoa(char *str, int *maxdig, int counter, int n)
{
	*maxdig = counter;
	if (n > 9 || n < -9)
		str = itoa(str, maxdig, counter + 1, n / 10);
	if (!str)
	{
		str = alloc().calloc(counter + 1 + (n < 0));
		if (!str)
			return (NULL);
		if (n < 0)
			str[0] = '-';
		str[counter + (n < 0)] = 0;
	}
	str[*maxdig - counter + (n < 0)] = (n % 10) * ((n > 0) - (n < 0)) + 48;
	return (str);
}

/*
	Compares two strings until n bytes
*/

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t	i;

	if (!s1 || !s2)
		return (-1);
	if (n == 0)
		return (n);
	i = -1;
	while (s1[++i] && s2[i] && s1[i] == s2[i] && i < n)
		;
	return ((unsigned char)*(s1 + i - (n == i)) - \
	(unsigned char)*(s2 + i - (n == i)));
}
