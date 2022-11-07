/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:47:43 by mtavares          #+#    #+#             */
/*   Updated: 2022/11/07 21:18:59 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/builtins.h"

int	exit_func(t_command **cmd, t_env *env)
{
	int	status;

	if ((*cmd)->args[1] && !is_nbr((*cmd)->args[1]))
		status = 2;
	else if ((*cmd)->args[1] && (*cmd)->args[2])
	{
		write(2, "exit: ", 6);
		write(2, (*cmd)->args[1], string().len((*cmd)->args[1], -1));
		write(2, ": too many arugments\n", 21);
		return (1);
	}
	else if ((*cmd)->args[1])
		status = string().atoi((*cmd)->args[1]);
	else
		status = 0;
	free_memory(cmd, env);
	if (env->env)
		alloc().free_matrix((void **)env->env);
	exit(status);
}

int	export(int out, t_command *cmd, t_env *env)
{
	int	i;
	int	j;

	i = 0;
	if (!cmd->args[1])
		print_exp(out, env->env);
	while (cmd->args[++i])
	{
		j = have_var(cmd->args[i], env->env);
		if (j != -1)
		{
			free(env->env[j]);
			env->env[j] = string().strdup(cmd->args[i]);
		}
		else
			if (deal_with_non_existing_var(cmd, i, this_env()))
				return (255);
	}
	return (0);
}

int	env(t_command *cmd, char **envp, int out)
{
	int	i;

	i = -1;
	if (!envp)
		printf("Env doesn't exist\n");
	while (cmd->args[++i])
		;
	if (i != 1)
		return (1);
	i = -1;
	while (envp[++i])
	{
		if (string().strchr(envp[i], '='))
		{
			write(out, envp[i], string().len(envp[i], -1));
			write(out, "\n", 1);
		}
	}
	return (0);
}

int	pwd(int out)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	if (!pwd)
	{
		perror("pwd");
		return (1);
	}
	write(out, pwd, string().len(pwd, -1));
	write(out, "\n", 1);
	free(pwd);
	return (0);
}

int	echo(t_command *cmd, int out)
{
	int	i;

	i = 0 + (!string().strncmp(cmd->args[1], "-n", 3));
	while (cmd->args[++i])
	{
		write(out, cmd->args[i], string().len(cmd->args[i], -1));
		if (cmd->args[i + 1])
			write(out, " ", 1);
	}
	if (string().strncmp(cmd->args[1], "-n", 3))
		write(out, "\n", 1);
	return (0);
}
