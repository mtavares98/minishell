/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:42:47 by mtavares          #+#    #+#             */
/*   Updated: 2022/10/29 13:11:45 by mtavares         ###   ########.fr       */
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
	char	*str;

	(void)ac;
	(void)av;
	this_env()->env = create_env(envp);
	if (!this_env()->env)
		return (printf("Error malloc on env\n"));
	while (1)
	{
		str = readline("MMshell>");
		counter()->mallocs++;
		receive_args(str);
		alloc().free_array(str);
		str = NULL;
		execution(this());
		free_commands(this());
	}
}
