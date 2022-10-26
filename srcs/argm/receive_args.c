/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   receive_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 16:52:55 by mgranate          #+#    #+#             */
/*   Updated: 2022/10/24 23:20:13 by mtavares         ###   ########.fr       */
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
	{
		if (str[word_len] == '"')
		{
			word_len++;
			while(str[word_len] && str[word_len] != '"')
				word_len++;
			if (word_len >= string().len(str, -1))
				return(string().len(str, -1));
		}
		if (str[word_len] == '\'' && *str)
		{
			word_len++;
			while(str[word_len] != '\'')
				word_len++;
			if (word_len >= string().len(str, -1))
				return(string().len(str, -1));
		}
		word_len++;
	}
	new_str = string().substr(str, 0, word_len);
	argm_handler(new_str);
	alloc().free_array((void *)new_str);
	return (word_len);
}

int	receive_args(char *str)
{
	int			i;

	while (*str)
	{
		i = select_string(str);
		if (!(str[i]))
			break ;
		str = str + i + 1;
	}
	return (1);
}
