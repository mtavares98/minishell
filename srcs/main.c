/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:42:47 by mtavares          #+#    #+#             */
/*   Updated: 2023/01/27 23:52:00 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <minishell.h>

void	control_d(char *str)
{
	if (str)
		return ;
	rl_clear_history();
	write(1, "exit\n", 6);
	if (this_env()->env)
		alloc().free_matrix((void **)this_env()->env);
	free_memory(this());
	exit(this_env()->status);
}

void	gen_handler(int signal)
{
	if (signal == SIGQUIT)
		return ;
	if (signal == SIGINT && !*this())
	{
		this_env()->status = 130;
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
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
		str = readline("MMshell$ ");
		control_d(str);
		counter()->mallocs++;
		if (str && *str)
			add_history(str);
		if (str && *str)
			receive_args(str);
		alloc().free_array(str);
		str = NULL;
		if (*this())
			execution(this());
	}
}
