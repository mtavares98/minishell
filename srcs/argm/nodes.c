/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate_ls <mgranate_ls@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 18:50:29 by mgranate          #+#    #+#             */
/*   Updated: 2023/01/25 01:23:14 by mgranate_ls      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	printlist(t_command *vars)
{
	int	j;
	int	i;

	i = 1;
	printf("===============\n");
	while (vars)
	{
		j = 0;
		printf("===== List nº %d=======\n", i);
		printf("Path == %s\n", vars->path);
		if (!vars->args)
			return ;
		while (vars->args[j])
		{
			printf("Arg[%d] == %s\n", j, vars->args[j]);
			j++;
		}
		vars = vars->next;
		i++;
	}
	printf("===============\n");
}

int	list_size(char **split, char *c)
{
	int	i;
	int	j;

	i = -1;
	while (split[++i])
	{
		j = -1;
		while (c[++j])
			if (c[j] == split[i][0])
				return(i);
	}
	return (i);
}

