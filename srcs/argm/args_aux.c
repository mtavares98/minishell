/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_aux.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 15:03:00 by mgranate          #+#    #+#             */
/*   Updated: 2022/10/16 15:28:13 by mgranate         ###   ########.fr       */
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
	int	ct;

	ct = 0;
	i = 0;
	while (str[++i] && str[i] != ap)
		;
	if (str[i] == ' ')
		return (i);
	while (str[++i])
	{
		while (str[i] && str[i] != ' ')
		{
			if (str[i] == ap)
				ct++;
			i++;
		}
		if (ct % 2 == 0)
			return (i);
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
		if (str[i] == '"' )
		{
			i = i + check_quotes(str + i, '"');
			return (i);
		}
		i++;
	}
	return (i);
}

int	ft_split_aux(char *s, int word_len, char c)
{
	if (*s == '\'' || *s == '"')
	{
		if (*s == '\'')
			word_len = check_quotes(s, '\'');
		else
			word_len = check_quotes(s, '"');
	}
	else if (!string().strchr(s, c))
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
		while (*s == c && *s)
			s++;
		if (*s == '\0')
			break ;
		word_len = ft_split_aux(s, word_len, c);
		lst[i++] = string().substr(s, 0, word_len);
		s += word_len;
	}
	lst[i] = NULL;
	return (lst);
}
