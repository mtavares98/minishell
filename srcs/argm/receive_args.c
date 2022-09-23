/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   receive_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 16:52:55 by mgranate          #+#    #+#             */
/*   Updated: 2022/09/23 15:06:37 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

//CHECK QUOTES IN STRING, ITS MISSPLACED, NEED TO ORGANIZE STILL

// int	check_bultin(char *btin, char *str)
// {
// 	int	i;
// 	int	ct;

// 	ct = 0;
// 	i = -1;
// 	while ((str[++i] && btin[i]) || str[i] == '|')
// 	{
// 		if (str[i] == btin[i])
// 			ct++;
// 		if (string().len(btin, -1) < string().len(str, -1))
// 		{
// 			if (str[string().len(btin, -1)] != ' ')
// 				return (0);
// 		}
// 	}
// 	if (string().len(btin, -1) == ct)
// 		return (1);
// 	return (0);
// }

int	receive_args(char *str)
{
	argm_handler(str);
	printlist(*this());
	return (1);
}
