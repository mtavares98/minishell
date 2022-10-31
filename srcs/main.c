/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:42:47 by mtavares          #+#    #+#             */
/*   Updated: 2022/10/31 10:42:03 by mgranate         ###   ########.fr       */
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
	t_command		*cmd;

	(void)ac;
	(void)av;
	(void)envp;

	while (1)
	{
		str = readline("MMshell>");
		counter()->mallocs++;
		receive_args(str);
		cmd = *this();
		//handle_env(envp, cmd);
		printlist(*this());
		while (cmd)
		{
			cmd = cmd->next;
			cmdfunc().remove(0);
		}
		alloc().free_array(str);
		str = NULL;
		printf("Mallocs == %d\n", (counter())->mallocs);
		printf("Fress == %d\n", (counter())->frees);
	}
}
