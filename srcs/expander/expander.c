/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 17:28:52 by mgranate          #+#    #+#             */
/*   Updated: 2022/11/15 12:24:30 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../includes/expander.h"

// This argmuent comes from echo
// Expander limits and specifications:
// 1. set creates variables on your system, created a struct called set that will hold does values
// 2. Dollar sign defines expansion, after dollar sign check for "{}" and see if we have a matching pair 
// 2.a. Use validate quotes to check 
// 3. Expander details:
// a. echo ${x:-$(ls)}  we have parameter x, which is undefined, so we start by looking
//	in the env vars if we have a matching var. If we do, in most cases we just print out the value of the
//	env var, if not defined we print out the value of the $(ls) => Which is the list of elements in directory

int	check_dollar(char *str, int i)
{
	
	return (1);
}

int	check_expander(t_command *cmd)
{
	int	i;

	i = 0;
	while (cmd->args[1][i] != '$')
	{
		if (cmd->args[1][i] == '$')
			check_dollar(cmd->args[1], i);
	}
}