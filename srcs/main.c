/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 20:59:45 by mtavares          #+#    #+#             */
/*   Updated: 2022/09/19 17:34:07 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_counter	*counter(void)
{
	static t_counter	*counter;

	return (counter);
}

int	main(void)
{
	char		*str;
	t_command	vars;

	while (1)
	{
		str = readline("MMshell>");
		receive_args(str, &vars);
		//counter()->mallocs++;
		//free(str);
	}
}
