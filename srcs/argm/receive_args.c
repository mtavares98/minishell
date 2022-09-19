/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   receive_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 16:52:55 by mgranate          #+#    #+#             */
/*   Updated: 2022/09/19 17:32:40 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	check_quotes(char *str, int *i, t_command *vars)
{
	int	ct;

	ct = 1;
	if (str[0] == '\'')
	{
		while (str[ct] != '\'')
		{
			if (string().len(str) - 1 == ct)
				return (0);
			i++;
			ct++;
		}
		vars->args[0] = string().substr(str, 0, ct);
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

int	receive_args(char *str, t_command *vars)
{
	int	i;

	i = 0;
	while (str[i])
	{
		printf("str[i] = %c\n", str[i]);
		if (((str[i] == '"' || str[i] == '\'') && !check_quotes(str + i, &i, vars)))
			return (0);
		// else if (str[i] == '|')
		// 	add_elements_list(str[i], vars);
		// else if ((str[i] == '<' || str[i] == '>') && !check_redirect(str + i, &i, vars))
		// 	return (0);
		// else if ((string().isalnum(str[i])))
		// 	create_elements(str + i, &i, vars);
		i++;
	}
	return (1);
}