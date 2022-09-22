/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   receive_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 16:52:55 by mgranate          #+#    #+#             */
/*   Updated: 2022/09/21 14:14:00 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

//CHECK QUOTES IN STRING, ITS MISSPLACED, NEED TO ORGANIZE STILL
int	check_quotes(char *str, int *i)
{
	char	*tmp;
	int		ct;

	ct = *i;
	if (str[*i] == '\'')
	{
		*i += 1;
		while (str[*i] && str[*i] != '\'')
			(*i)++;
		if (*i == string().len(str, -1))
			return (0);
		printf("i = %d\n", *i);
		printf("ct = %d\n", ct);
		tmp = string().substr(str, ct, *i - ct + 1);
		printf("tmp = %s\n", tmp);
		free(tmp);
		return (1);
	}
	if (str[*i] == '"')
	{
		*i += 1;
		while (str[*i] && str[*i] != '"')
			(*i)++;
		tmp = string().substr(str, ct, *i - ct + 1);
		printf("tmp2 = %s\n", tmp);
		free(tmp);
		return (1);
	}
	return (1);
}

int	check_bultin(char *btin, char *str)
{
	int	i;
	int	ct;

	ct = 0;
	i = -1;
	while ((str[++i] && btin[i]) || str[i] == '|')
	{
		if (str[i] == btin[i])
			ct++;
		if (string().len(btin, -1) < string().len(str, -1))
		{
			if (str[string().len(btin, -1)] != ' ')
				return (0);
		}
	}
	if (string().len(btin, -1) == ct)
		return (1);
	return (0);
}

int	identify_command(char *str)
{
	if (check_bultin("echo", str))
	{
		argm_handler(str);
	}
	return (1);
}

int	receive_args(char *str)
{
	identify_command(str);
	printlist(*this());
	return (1);
}
