/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 22:32:11 by mtavares          #+#    #+#             */
/*   Updated: 2023/01/31 14:04:17 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	set_env(t_command *cmd, t_env *env, int i)
{
	char	**tmp;
	int		len;
	int		j;
	int		k;

	tmp = env->env;
	len = length(env->env);
	env->env = alloc().calloc(sizeof(char *) * len);
	if (!env->env)
		return (1);
	j = -1;
	k = 0;
	while (tmp[++j])
	{
		if (!string().strncmp(cmd->args[i], tmp[j], \
		string().len(cmd->args[i], -1)))
			alloc().free_array((void *)tmp[j]);
		else
			env->env[k++] = tmp[j];
	}
	alloc().free_array((void *)tmp);
	return (0);
}

int	is_unset(t_command *cmd, char **env, int i)
{
	int	j;

	j = -1;
	while (env[++j])
		if (!string().strncmp(cmd->args[i], env[j], \
		string().len(cmd->args[i], -1) - 1))
			return (1);
	return (0);
}

int	unset(t_command *cmd, t_env *env)
{
	int	i;

	i = -1;
	while (cmd->args[++i])
	{
		if (is_unset(cmd, env->env, i))
		{
			env->status = set_env(cmd, env, i);
			if (env->status)
				return (1);
		}
	}
	return (0);
}

int	change_env(t_env *env)
{
	char	*tmp;
	int		i;

	i = -1;
	while (env->env[++i])
		if (!string().strncmp(env->env[i], "PWD=", 4))
			break ;
	tmp = string().strjoin("OLD", env->env[i]);
	alloc().free_array((void *)env->env[i]);
	env->env[i] = tmp;
	i = -1;
	while (env->env[++i])
		if (!string().strncmp(env->env[i], "OLDPWD=", 7))
			break ;
	tmp = getcwd(NULL, 0);
	counter()->mallocs++;
	alloc().free_array((void *)env->env[i]);
	env->env[i] = string().strjoin("PWD=", tmp);
	alloc().free_array((void *)tmp);
	return (0);
}

int	cd(t_command *cmd, t_env *env)
{
	if (!cmd->args[1])
		if (set_var(cmd))
			return (1);
	if (cmd->args[2])
	{
		print_error(cmd, 1, ": too many arguments\n");
		return (1);
	}
	if (chdir(cmd->args[1]))
	{
		perror("chdir");
		return (1);
	}
	if (change_env(env))
		return (1);
	return (0);
}
