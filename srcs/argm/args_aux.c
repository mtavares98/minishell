/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_aux.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 15:03:00 by mgranate          #+#    #+#             */
/*   Updated: 2023/02/01 16:43:02 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static size_t	ft_countword(char *s)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (string().ft_isspace(*s))
			s++;
		if (*s && *s != '<' && *s != '>' && *s != '|')
			count++;
		while (*s && !string().ft_isspace(*s))
		{
			if (*s == '"' || *s == '\'')
				s += skip_quotes(s + 1, '"' + 5 * (*s == '\''));
			if ((*s == '<' || *s == '>' || *s == '|'))
			{
				s += check_reds(s);
				count++;
				break ;
			}
			if (!*s)
				break ;
			s++;
		}
	}
	return (count);
}

int	split_len(char *s)
{
	int	i;

	i = string().len(s, -1);
	if (*s == '>' || *s == '<' || *s == '|')
		return (check_reds(s));
	while (*s)
	{
		if (*s == '"')
			s += skip_quotes(s + 1, '"');
		if (*s == '\'')
			s += skip_quotes(s + 1, '\'');
		if (*s == '>' || *s == '<')
			break ;
		if (*s && string().ft_isspace(*s))
			return (i - string().len(s, -1));
		if (!*s)
			break ;
		s++;
	}
	return (i - string().len(s, -1));
}

char	**ft_split(char *s)
{
	char	**split;
	int		sz;
	int		i;
	int		cw;

	if (!s)
		return (NULL);
	cw = ft_countword(s) + 1;
	split = alloc().calloc(sizeof(char *) * (cw));
	if (!split)
		return (NULL);
	i = 0;
	while (--cw > 0)
	{
		while (*s && string().ft_isspace(*s))
			s++;
		sz = split_len(s);
		split[i] = alloc().calloc(sz + 1);
		if (!split[i])
			return (NULL);
		splitcpy(split[i++], s, sz);
		s += sz;
	}
	split[i] = 0;
	return (split);
}
