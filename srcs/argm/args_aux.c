/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_aux.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 15:03:00 by mgranate          #+#    #+#             */
/*   Updated: 2022/11/21 21:57:03 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static size_t	ft_countword(char const *s, char c)
{
	size_t	count;

	if (!*s)
		return (0);
	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s != c && *s)
			s++;
	}
	return (count);
}

int	check_quotes(char *str, char ap)
{
	int	i;

	i = 0;
	while (str[++i] && str[i] != ap)
		;
	if (str[i + 1] && string().ft_isspace(str[i + 1]))
		return (i);
	while (str[i])
	{
		while (str[i] && str[i] != ' ')
			i++;
		if (!str[i])
			return (i);
		i++;
	}
	return (i);
}

int	add_quotes(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != ' ')
	{
		if (str[i] == '\'' )
		{
			i = i + check_quotes(str + i, '\'');
			return (i);
		}
		if (str[i] == '"')
		{
			i = i + check_quotes(str + i, '"');
			return (i);
		}
		i++;
	}
	return (i);
}

int	ft_split_aux(char *s, int word_len)
{
	if (*s == '\'' || *s == '"')
	{
		if (*s == '\'')
			word_len = check_quotes(s, '\'');
		else
			word_len = check_quotes(s, '"');
	}
	else if (check_spaces(s))
		word_len = string().len(s, -1);
	else
		word_len = add_quotes(s);
	return (word_len);
}

char	**ft_split(char *s, char c)
{
	char	**lst;
	size_t	word_len;
	int		i;

	if (!s)
		return (0);
	lst = alloc().calloc((ft_countword(s, c) + 1) * sizeof(char *));
	if (!lst)
		return (0);
	i = 0;
	while (*s)
	{
		while (string().ft_isspace(*s) && *s)
			s++;
		if (*s == '\0')
			break ;
		word_len = ft_split_aux(s, word_len);
		lst[i++] = string().substr(s, 0, word_len);
		s += word_len;
	}
	lst[i] = NULL;
	return (lst);
}
