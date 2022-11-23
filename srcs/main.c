/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:42:47 by mtavares          #+#    #+#             */
/*   Updated: 2022/11/23 01:05:32 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	control_d(char *str)
{
	if (str)
		return ;
	rl_clear_history();
	write(1, "exit\n", 5);
	exit(this_env()->status);
}

void	gen_handler(int signal)
{
	if (signal == SIGQUIT)
		return ;
	if (signal == SIGINT)
	{
		this_env()->status = 130;
		rl_replace_line("", 0);
		write(1, "\n", 1);
		rl_on_new_line();
		rl_redisplay();
	}
	return ;
}

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

	(void)ac;
	(void)av;
	signal(SIGQUIT, gen_handler);
	signal(SIGINT, gen_handler);
	this_env()->env = create_env(envp);
	if (!this_env()->env)
		return (printf("Error malloc on env\n"));
	while (1)
	{
		str = readline("MMshell$");
		counter()->mallocs++;
		if (str && *str)
			add_history(str);
		control_d(str);
		receive_args(str);
		alloc().free_array(str);
		str = NULL;
		execution(this());
	}
}
