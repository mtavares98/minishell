/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_argms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 22:54:18 by mgranate          #+#    #+#             */
/*   Updated: 2022/11/03 02:02:27 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// É preciso ainda retirar as aspas dos argumentos antes de os imprimir.
void	env_arg(t_command *cmd, t_env *env)
{
	int	i;

	i = 0;
	while(cmd->args[++i])
	{
		if(!string().strchr(cmd->args[i], '='))
		{
			printf("env: ‘%s’: No such file or directory\n", cmd->args[i]);
			return ;
		}
	}
	i = 0;
	print_env(env);
	while (cmd->args[++i])
		printf("%s\n", cmd->args[i]);
}

char	**remove_env(int rm, t_env *env)
{
	char **tmp_env;

	tmp_env = create_env(env->env, rm);
	//env->env = create_env(tmp_env, -1);
	//print_env(env);
	alloc().free_array(env->env);
	return (tmp_env);
}

void	unset_arg(char *argm, t_env *env)
{
	int		i;
	char	*tmp;
	int		ct;

	(void)argm;
	i = -1;
	while (env->env[++i])
	{
		ct = string().len(env->env[i], '=') - 1;
		tmp = string().substr(env->env[i], 0, ct);
		if (string().contains(tmp, argm, string().len(argm, -1)))
			env->env = remove_env(i, env);
	}
}