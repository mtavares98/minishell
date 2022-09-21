/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:42:47 by mtavares          #+#    #+#             */
/*   Updated: 2022/09/21 14:43:53 by mtavares         ###   ########.fr       */
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
	t_command		**cmd;
	t_redirection	red;
	char			*str;

	(void)ac;
	(void)av;
	(void)envp;
	while (1)
	{
		str = readline("MMshell>");
		receive_args(str);
		counter()->mallocs++;
		cmd = this();
		exec_main(cmd, &red, envp);
		alloc().free_array(str);
		(counter())->mallocs++;
	}
}
