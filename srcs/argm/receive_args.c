/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   receive_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 16:52:55 by mgranate          #+#    #+#             */
/*   Updated: 2022/10/31 11:31:04 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	select_string(char *str)
{
	int		word_len;
	char	*new_str;
	
	new_str = NULL;
	word_len = 0;
	while (str[word_len] && str[word_len] != '|')
		word_len++;
	new_str = string().substr(str, 0, word_len);
	argm_handler(new_str);
	alloc().free_array((void *)new_str);
	return (word_len);
}
int	count_quotes(char *str, int	i, char c)
{
	while (str[i] && str[i] != c)
		i++;
	if (str[i] == c)
		return(i + 1);
	return (0);
}

int	validate_quotes(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\'' )
		{
			if (!count_quotes(str, i + 1, '\''))
			{
				printf("Wrong Use of Quotes\n");
				return (0);
			}
			i = count_quotes(str, i + 1, '\'');
		}
		if (str[i] == '"')
		{
			if (!count_quotes(str, i + 1, '"'))
			{
				printf("Wrong Use of Quotes\n");
				return (0);
			}
			i = count_quotes(str, i + 1, '"');
		}
		if (i > string().len(str, -1))
			return (1);
		i++;
	}
	return (1);
}

int	receive_args(char *str)
{
	int			i;

	if (!validate_quotes(str))
		return (0);
	while (*str)
	{
		i = select_string(str);
		if (!(str[i]))
			break ;
		str = str + i + 1;
	}
	return (1);
}
