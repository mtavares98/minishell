/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   receive_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 16:52:55 by mgranate          #+#    #+#             */
/*   Updated: 2023/01/31 14:03:26 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_quotes(char *str, int i, char c)
{
	if (!str[i + 1])
	{
		printf("Wrong Use of Quotes\n");
		return (0);
	}
	i++;
	while (str[i] && str[i] != c)
		i++;
	if (str[i] == c)
		return (i);
	printf("Wrong Use of Quotes\n");
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
			i = count_quotes(str, i, '\'');
			if (i == 0)
				return (0);
		}
		if (str[i] == '"')
		{
			i = count_quotes(str, i, '"');
			if (i == 0)
				return (0);
		}
		i++;
		if (i >= string().len(str, -1))
			return (1);
	}
	return (1);
}

int	receive_args(char *str)
{
	if (!validate_quotes(str))
		return (0);
	argm_handler(str);
	return (1);
}
