/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:42:47 by mtavares          #+#    #+#             */
/*   Updated: 2022/11/04 23:50:29 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include "../includes/env.h"

void	free_commands(t_command **cmd)
{
	while (*cmd)
		cmdfunc().remove(0);
}

t_counter	*counter(void)
{
	static t_counter	counter;

	return (&counter);
}

int	main(int ac, char **av, char **envp)
{
	char	*str;
	t_command	*cmd;

	(void)ac;
	(void)av;
	this_env()->env = create_env(envp, -1);
	if (!this_env()->env)
		return (printf("Error malloc on env\n"));
	while (1)
	{
		str = readline("MMshell>");
		counter()->mallocs++;
		receive_args(str);
		cmd = *this();
		handle_env(cmd);
		//printlist(*this());
		while (cmd)
		{
			cmd = cmd->next;
			cmdfunc().remove(0);
		}
		alloc().free_array(str);
		str = NULL;
		execution(this());
	}
}
