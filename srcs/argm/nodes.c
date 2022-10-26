/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 18:50:29 by mgranate          #+#    #+#             */
/*   Updated: 2022/10/24 23:19:50 by mtavares         ###   ########.fr       */
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

int	list_size(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}

t_tmp	*create_single_node(char *value)
{
	t_tmp	*strc;
	strc = alloc().calloc(sizeof(t_tmp));
	if (!strc)
		return (0);
	strc->args = alloc().calloc(string().len(value, -1) + 1);
	if (!strc->args)
		return (0);
	strc->args = value;
	strc->next = NULL;
	return (strc);
}
