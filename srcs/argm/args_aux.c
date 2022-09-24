/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_aux.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 15:03:00 by mgranate          #+#    #+#             */
/*   Updated: 2022/09/24 10:28:20 by mgranate         ###   ########.fr       */
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

// Aspas e Duplas Aspas:
// 1- Iterar até encontrar uma aspa;
// 2- Verificar se o caracter a seguir é espaço
// 3A- Caso não seja aspas, iterar até encontrar um espaço
// 3B- Caso seja aspas, incrementar o contador de aspas, e iterar até encontrar a proxima aspa
// - Repetir os passos 

int	check_quotes(char *str, char ap)
{
	int	i;
	int	ct;

	ct = 0;
	i = 0;
	
	while (str[++i] && str[i] != ap)
		;
	if (str[i + 1] == ' ')
		return (i + 1);
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
		//There is an Edgecase here: when the word has quotes in the middle of the word and not beginig
		// example: fasnakn"fas jkj" ->It will separate both
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
			word_len = string().strchr(s, c) - s;
		lst[i++] = string().substr(s, 0, word_len);
		s += word_len;
	}
	lst[i] = NULL;
	return (lst);
}