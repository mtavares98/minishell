/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 19:43:44 by mgranate          #+#    #+#             */
/*   Updated: 2022/11/30 15:33:43 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

//Redirections List, does not handle "|" yet
//Still haven't apllied the clean function. REMINDER
 
int	list_size1(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}

char	**argms_node1(char **args, char **split)
{
	int	i;

	i = -1;
	args = alloc().calloc((list_size1(split) + 1) * sizeof(char **));
	while (split[++i])
		args[i] = string().strdup(split[i]);
	args[i] = NULL;
	return (args);
}

int	get_redirections(char **split)
{
	static t_red *red;

	red = malloc(sizeof(t_red) * 1);
	red->args = argms_node1(red->args, split);
	return (-1);
}

int	check_redirection(char **split)
{
	int	i;

	i = -1;
	while (split[++i])
	{
		if (!string().strncmp(split[i], ">", string().len(split[i], -1)))
			i = get_redirections(split);
		else if (!string().strncmp(split[i], ">>", string().len(split[i], -1)))
			i = get_redirections(split);
		else if (!string().strncmp(split[i], "<", string().len(split[i], -1)))
			i = get_redirections(split);
		else if (!string().strncmp(split[i], "<<", string().len(split[i], -1)))
			i = get_redirections(split);
		if (i == -1)
			return (1);
	}
return (0);
}