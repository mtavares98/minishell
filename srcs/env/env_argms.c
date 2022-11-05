/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_argms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 22:54:18 by mgranate          #+#    #+#             */
/*   Updated: 2022/11/04 23:44:08 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	remove_aux(char *argm, char c, int i)
{
	char	*tmp;
	int		j;
	int		ct;

	ct = 0;
	j = -1;
	tmp = alloc().calloc(string().len(argm, -1) - 1);
	while (++j < i)
		tmp[j] = argm[j];
	while (argm[++i])
	{
		if (argm[i] == c && ct == 0)
		{
			ct = i - 2;
			i++;
			if (i >= string().len(argm, -1))
				break ;
		}
		tmp[j++] = argm[i];
	}
	argm = string().strdup(tmp);
	//i = -1;
	// while (tmp[++i])
	// 	argm[i] = tmp[i];
	// i--;
	// while (argm[++i])
	// 	argm[i] = 0;
	alloc().free_array(tmp);
	return (ct);
}

char	*remove_quotes(char *argm)
{
	int	i;

	i = -1;
	while (argm[++i])
	{
		if (argm[i] == '\'' )
			i = remove_aux(argm, '\'', i);
		else if (argm[i] == '"')
			i = remove_aux(argm, '"', i);
		if (i >= string().len(argm, -1))
			return (argm);
	}
	return (argm);
}

void	env_arg(t_command *cmd, t_env *env)
{
	int	i;

	(void)env;
	i = 0;
	while (cmd->args[++i])
	{
		if (!string().strchr(cmd->args[i], '='))
		{
			printf("env: ‘%s’: No such file or directory\n", cmd->args[i]);
			return ;
		}
	}
	i = 0;
	print_env(env->env, cmd);
}

char	**remove_env(int rm, t_env *env)
{
	char	**tmp_env;

	tmp_env = create_env(env->env, rm);
	//env->env = create_env(tmp_env, -1);
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
