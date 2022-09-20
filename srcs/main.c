/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 20:59:45 by mtavares          #+#    #+#             */
/*   Updated: 2022/09/19 17:35:27 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	create_cmd(t_redirection *red)
{
	char	*path;
	char	**args;

	path = string().strdup("echo");
	if (!path)
		return (printf("Error with strdup\n"));
	args = alloc().calloc(3, sizeof(char *));
	if (!args)
		return (printf("Error with calloc\n"));
	args[0] = string().strdup("echo");
	args[1] = string().strdup("hahah\nahahah");
	cmdfunc().add(path, args);
	path = string().strdup("/bin/ls");
	args = alloc().calloc(3, sizeof(char *));
	if (!args)
		return (printf("Error with calloc\n"));
	args[0] = string().strdup("grep");
	args[1] = string().strdup("ha");
	cmdfunc().add(path, args);
	red->infd = -1;
	red->infile = ".heredoc";
	red->limiter = "EOF";
	red->is_trunc = 0;
	red->outfd = -1;
	red->outfile = "outfile";
	return (0);
}

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
		counter()->mallocs++;
		create_cmd(&red);
		cmd = this(command());
		exec_main(cmd, &red, envp);
		alloc().free_array(str);
	}
}
