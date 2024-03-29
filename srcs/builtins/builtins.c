/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:47:43 by mtavares          #+#    #+#             */
/*   Updated: 2023/02/01 16:59:47 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	exit_func(t_command **cmd, t_env *env)
{
	unsigned char	status;

	printf_fd(1, "exit\n");
	if ((*cmd)->args[1] && !is_nbr((*cmd)->args[1]))
		status = print_error(*cmd, 2, ": numeric argument required\n");
	else if ((*cmd)->args[1] && (*cmd)->args[2])
	{
		status = print_error(*cmd, 1, ": too many arugments\n");
		return (status);
	}
	else if ((*cmd)->args[1])
		status = (unsigned char)string().atoi((*cmd)->args[1]);
	else
		status = env->status;
	free_memory(cmd);
	if (env->env)
		alloc().free_matrix((void **)env->env);
	rl_clear_history();
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
		if (is_valid(cmd->args[i]))
		{
			j = have_var(cmd->args[i], env->env);
			if (j != -1 && \
			cmd->args[i][string().len(cmd->args[i], '=') - 1] == '=')
			{
				free(env->env[j]);
				env->env[j] = string().strdup(cmd->args[i]);
			}
			else if (j == -1)
				if (deal_with_non_existing_var(cmd, i, this_env()))
					return (255);
		}
		else
			print_error(cmd, 127, ": not a valid identifier\n");
	}
	return (0);
}

int	env(t_command *cmd, char **envp, int out)
{
	int	i;

	i = -1;
	if (!envp)
		printf_fd(2, "Env doesn't exist\n");
	while (cmd->args[++i])
		;
	if (i > 1)
		return (1);
	i = -1;
	while (envp[++i])
	{
		if (string().strchr(envp[i], '='))
			printf_fd(out, "%s\n", envp[i]);
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
	printf_fd(out, "%s\n", pwd);
	free(pwd);
	return (0);
}

int	echo(t_command *cmd, int out)
{
	int	i;

	i = 0 + (!string().strncmp(cmd->args[1], "-n", 3));
	while (cmd->args[++i])
	{
		printf_fd(out, cmd->args[i]);
		if (cmd->args[i + 1])
			printf_fd(out, " ");
	}
	if (string().strncmp(cmd->args[1], "-n", 3))
		printf_fd(out, "\n");
	return (0);
}
