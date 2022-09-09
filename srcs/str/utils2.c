/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 22:26:25 by mtavares          #+#    #+#             */
/*   Updated: 2022/09/10 00:31:39 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/str.h"

/*
	Function that return true if a char is number
		if i isn't returns false
*/

int	is_dig(char c)
{
	return (c >= '0' && c <= '9');
}

/*
	Itoa converts a number into a string the counter start at 1 because you
		 will always 1 digit
*/

static char	*itoa(char *str, int *maxdig, int counter, int n)
{
	*maxdig = counter;
	if (n > 9 || n < -9)
		str = itoa(str, maxdig, counter + 1, n / 10);
	if (!str)
	{
		str = malloc(sizeof(char) * (counter + 1 + (n < 0)));
		if (!str)
			return (NULL);
		if (n < 0)
			str[0] = '-';
	}
	str[*maxdig - counter + (n < 0)] = (n % 10) * ((n > 0) - (n < 0)) + 48;
	return (str);
}

/*
	Compares two strings until n bytes
*/

int	ft_strncmp(unsigned char *s1, unsigned char *s2, size_t n)
{
	int	i;

	if (!s1 || !s2)
		return (1);
	if (!n)
		return (0);
	i = -1;
	while (++i < n && s1[i] && s2[i] && s1[i] == s2[i])
		;
	return (s1[i] - s2[i]);
}
