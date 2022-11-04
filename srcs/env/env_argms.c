/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_argms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 22:54:18 by mgranate          #+#    #+#             */
/*   Updated: 2022/11/04 12:55:25 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	remove_aux(char *argm, char c, int i)
{
	char	*tmp;
	int		j;

	j = i;
	tmp = argm;
	while (tmp[++j])
	{
		if (tmp[j] == c)
		{
			j++;
			argm[i] = tmp[j];
		}
		argm[i] = tmp[j];
		i++;
	}
	printf("Argm == %s\n", argm);
	return (i);
}

char	*remove_quotes(char *argm)
{
	int 	i;

	i = -1;
	while (argm[++i])
	{
		if (argm[i] == '\'' )
			i = remove_aux(argm, '\'', i);
		if (argm[i] == '"')
		{
			i = remove_aux(argm, '"', i);
			printf("I == %d\n", i);
			printf("Argm == %s\n", argm);
		}
		if (i == -1)
			return (argm);
	}
	while (argm[i])
	{
		argm[i] = 0;
		i++;
	}
	return (argm);
}

// É preciso ainda retirar as aspas dos argumentos antes de os imprimir.
void	env_arg(t_command *cmd, t_env *env)
{
	int	i;

	(void)env;
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
	//print_env(env);
	while (cmd->args[++i])
	{
		remove_quotes(cmd->args[i]);
		printf("%s\n", cmd->args[i]);
	}
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
