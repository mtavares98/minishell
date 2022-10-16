/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 18:50:29 by mgranate          #+#    #+#             */
/*   Updated: 2022/10/01 17:13:42 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	printlist(t_command *vars)
{
	int	j;
	int	i;
	
	i = 1;
	printf("\n==============\n");
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
		//printf("Status == [%d] ", vars->ready);
		vars = vars->next;
		i++;
	}
	printf("\n===============\n");
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
