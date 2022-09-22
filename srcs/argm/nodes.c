/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 18:50:29 by mgranate          #+#    #+#             */
/*   Updated: 2022/09/21 14:18:58 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	printlist(t_command *vars)
{
	int	j;

	j = 0;
	printf("\n==============\n");
	while (vars)
	{
		printf("Path == %s\n", vars->path);
		while (vars->args[j])
		{
			printf("Arg[%d] == %s\n", j, vars->args[j]);
			j++;
		}
		printf("Status == [%d] ", vars->ready);
		vars = vars->next;
	}
	printf("\n===============\n");
}

int	list_size(t_tmp_arg *list)
{
	int	i;

	i = 0;
	while (list->next && i++)
		list = list->next;
	return (i);
}

t_tmp_arg	*create_single_node(char *value)
{
	t_tmp_arg	*strc;
	
	strc = (t_tmp_arg *)malloc(sizeof(t_tmp_arg));
	if (!strc)
		return (0);
	strc->args = (char *)malloc(sizeof(char *)* (string().len(value, -1) + 1));
	if (!strc->args)
		return (0);
	strc->args = value;
	strc->next = NULL;
	return (strc);
}
