/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:42:47 by mtavares          #+#    #+#             */
/*   Updated: 2022/09/26 16:28:24 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_counter	*counter(void)
{
	static t_counter	counter;

	return (&counter);
}

int	main(int ac, char **av, char **envp)
{
	char			*str;

	(void)ac;
	(void)av;
	(void)envp;
	while (1)
	{
		str = readline("MMshell>");
		counter()->mallocs++;
		receive_args(str);
		alloc().free_array(str);
		str = NULL;
		printf("Mallocs == %d\n", (counter())->mallocs);
		printf("Fress == %d\n", (counter())->frees);
	}
}
