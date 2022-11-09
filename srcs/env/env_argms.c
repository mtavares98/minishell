/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_argms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 22:54:18 by mgranate          #+#    #+#             */
/*   Updated: 2022/11/09 00:15:59 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	remove_aux(char c, int *i, char *tmp)
{
	int		j;
	int		ct;

	ct = -1;
	while (++ct < 2)
	{
		j = *i - 1;
		while (tmp[++j])
			tmp[j] = tmp[j + 1];
		tmp[j] = 0;
		while (tmp[*i] != c && ct == 0)
			(*i)++;
	}
	*i -=1;
}

char	*remove_quotes(char *argm)
{
	int		i;
	char	*tmp;

	i = -1;
	tmp = string().strdup(argm);
	while (tmp[++i])
	{
		if (tmp[i] == '\'' )
			remove_aux( '\'', &i, tmp);
		else if (tmp[i] == '"')
			remove_aux('"', &i, tmp);
		if (i >= string().len(tmp, -1))
			return (tmp);
	}
	return (tmp);
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
