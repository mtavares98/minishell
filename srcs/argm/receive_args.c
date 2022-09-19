/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   receive_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 16:52:55 by mgranate          #+#    #+#             */
/*   Updated: 2022/09/19 21:49:40 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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
		if (*i == string().len(str))
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

// int	add_elements_list(char a, t_command *vars)
// {
// 	printf("Str_pipe = %c\n", a);
// 	return (1);
// }

// int check_redirect(char *str, int *i, t_command *vars)
// {
// 	printf("i = %i\n", *i);
// 	printf("Str_redirect = %s\n", str);
// 	return (1);
// }

// int	create_elements(char *str, int *i, t_command *vars)
// {
// 	printf("i = %ls\n", i);
// 	printf("Str_elements = %s\n", str);
// 	return (1);
// }

int	receive_args(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (((str[i] == '"' || str[i] == '\'') && !check_quotes(str, &i)))
			return (0);
		// else if (str[i] == '|')
		// 	add_elements_list(str[i], vars);
		// else if ((str[i] == '<' || str[i] == '>') && !check_redirect(str + i, &i, vars))
		// 	return (0);
		// else if ((string().isalnum(str[i])))
		// 	create_elements(str + i, &i, vars);
	}
	return (1);
}