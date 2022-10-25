/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_aux2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 15:47:40 by mgranate          #+#    #+#             */
/*   Updated: 2022/10/21 16:37:57 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/arguments.h"

char	*get_substring(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != c)
		i++;
	while (str[i] && !(string().ft_isspace(str[i])))
		str[i++] = ' ';
	return (str);
}

char	**recicly_split(char **split)
{
	int		i;
	int		j;
	char	**new_split;

	new_split = split;
	i = 0;
	while (new_split[i])
	{
		j = 0;
		while (new_split[i][j])
		{
			new_split[i][j] = '\0';
			j++;
		}
		i++;
	}
	return (new_split);
}
