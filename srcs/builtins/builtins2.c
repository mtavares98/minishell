/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 22:32:11 by mtavares          #+#    #+#             */
/*   Updated: 2022/11/06 23:14:11 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/builtins.h"

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
	if (cmd->args[1] && cmd->args[2])
	{
		write(2, "cd: too many arguments\n", 23);
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
