/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 17:18:32 by mtavares          #+#    #+#             */
/*   Updated: 2022/08/31 18:15:19 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	parse_args(char **s)
{
	char	**new_str;
	int		i;

	new_str = __str__().split(*s, " rv");
	if (!new_str)
	{
		printf("correu mal\n");
		return ;
	}
	i = -1;
	while (new_str[++i])
	{
		printf("%s\n", new_str[i]);
		free(new_str[i]);
	}
	free(new_str);
	free(*s);
	return ;
}
