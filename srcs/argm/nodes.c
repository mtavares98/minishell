/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 18:50:29 by mgranate          #+#    #+#             */
/*   Updated: 2022/09/19 19:12:50 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	printlist(t_command *vars, char *list)
{
	printf("\n=======%s=======\n", list);
	while (vars)
	{
		printf("%s ", vars->path);
		vars = vars->next;
	}
	printf("\n===============\n");
}

// void	add_arguments(char **args)
// {
	
// }

// void	create_new_node(char **args, char *path, t_command *vars)
// {
// 	vars = (t_command *)malloc(sizeof(t_command));
// 	if (!vars)
// 		return ;
// 	//add_arguments(args);
// 	args = NULL;
// 	vars->path = path;
// 	vars->next = NULL;
// }
