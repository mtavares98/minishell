/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:42:47 by mtavares          #+#    #+#             */
/*   Updated: 2022/10/31 14:20:03 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

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
	char	**env;
	char	*str;

	(void)ac;
	(void)av;
	env = create_env(envp);
	if (!env)
		return (printf("Error malloc on env\n"));
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
		// str = NULL;
		execution(this(), env);
		// printlist(*this());
		free_commands(this());
	}
}
