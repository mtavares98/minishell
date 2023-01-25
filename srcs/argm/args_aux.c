/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_aux.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 15:03:00 by mgranate          #+#    #+#             */
/*   Updated: 2023/01/25 22:06:21 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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
			if (*s == '"')
				s += skip_quotes(s + 1, '"');
			if (*s == '\'')
				s += skip_quotes(s + 1, '\'');
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
	cw = ft_countword(s);
	split = alloc().calloc(sizeof(char *) * (cw + 1));
	if (!split)
		return (NULL);
	i = 0;
	while (cw > 0)
	{
		while (*s && string().ft_isspace(*s))
			s++;
		sz = split_len(s);
		split[i] = alloc().calloc(sz + 1);
		splitcpy(split[i], s, sz);
		s += sz;
		cw--;
		i++;
	}
	split[i] = 0;
	return (split);
}
