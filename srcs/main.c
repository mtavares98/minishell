/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:42:47 by mtavares          #+#    #+#             */
/*   Updated: 2023/01/27 15:36:45 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../includes/minishell.h"

void	print_list(t_command *begin)
{
	t_red	*tmp;
	int		i;

	while (begin)
	{
		printf_fd(1, "FDS\n");
		printf_fd(1, "input %i\n", begin->infd);
		printf_fd(1, "output %i\n", begin->outfd);
		printf_fd(1, "END FDS\n");
		printf_fd(1, "Command\n");
		printf_fd(1, "Path\n");
		printf_fd(1, "%s\n", begin->path);
		printf_fd(1, "CMD\n");
		i = -1;
		while (begin->args && begin->args[++i])
			printf_fd(1, "%s\n", begin->args[i]);
		printf_fd(1, "End Command\n");
		printf_fd(1, "Redirections\n");
		this_red(begin->io);
		tmp = *this_red(NULL);
		printf("%p\n", *this_red(NULL));
		while (tmp)
		{
			printf_fd(1, "%s\n", tmp->file);
			printf_fd(1, "is_double = %i\n", tmp->is_double);
			printf_fd(1, "is_output = %i\n", tmp->is_output);
			tmp = tmp->next;
		}
		printf_fd(1, "End Redirections\n\n");
		begin = begin->next;
	}
}

void	control_d(char *str)
{
	unsigned char	status;

	if (str)
		return ;
	rl_clear_history();
	write(1, "\nexit\n", 6);
	if (this_env()->env)
		alloc().free_matrix((void **)this_env()->env);
	status = (unsigned char)this_env()->status;
	exit(status);
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
