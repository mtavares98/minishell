/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 20:59:45 by mtavares          #+#    #+#             */
/*   Updated: 2022/09/17 14:31:07 by mtavares         ###   ########.fr       */
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
	char	*str;

	while (1)
	{
		str = readline("MMshell>");
		counter()->mallocs++;
		free(str);
	}
}
