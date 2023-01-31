/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_aux2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 15:47:40 by mgranate          #+#    #+#             */
/*   Updated: 2023/01/31 14:02:59 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arguments.h"

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
	i = -1;
	while (new_split[++i])
	{
		j = -1;
		while (new_split[i][++j])
			new_split[i][j] = '\0';
	}
	return (new_split);
}

int	check_spaces(char *s)
{
	while (*s)
	{
		if (!string().ft_isspace(*s))
			return (0);
		s++;
	}
	return (1);
}

static void	remove_aux(char c, int *i, char *tmp)
{
	int		j;
	int		ct;

	ct = -1;
	while (++ct < 2)
	{
		j = *i - 1;
		while (tmp[++j])
			tmp[j] = tmp[j + 1];
		tmp[j] = 0;
		while (tmp[*i] && tmp[*i] != c && ct == 0)
			(*i)++;
	}
	*i -= 1;
}

char	*remove_quotes(char *argm)
{
	int		i;
	char	*tmp;

	i = -1;
	tmp = string().strdup(argm);
	if (!tmp)
		return (NULL);
	while (tmp[++i])
	{
		if (tmp[i] == '\'' )
			remove_aux('\'', &i, tmp);
		else if (tmp[i] == '"')
			remove_aux('"', &i, tmp);
		if (i >= string().len(tmp, -1))
			return (tmp);
	}
	alloc().free_array(argm);
	return (tmp);
}
