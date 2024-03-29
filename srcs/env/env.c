/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:55:41 by mtavares          #+#    #+#             */
/*   Updated: 2023/01/31 14:05:13 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*shell_lvl(char *envp)
{
	char	*env;
	char	*tmp;
	int		i;

	i = 0;
	tmp = string().itoa(NULL, &i, 1, string().atoi(envp) + 1);
	if (!tmp)
		return (NULL);
	env = string().strjoin("SHLVL=", tmp);
	if (!env)
		return (NULL);
	alloc().free_array(tmp);
	return (env);
}

t_env	*this_env(void)
{
	static t_env	env;

	return (&env);
}

char	**create_env(char **envp)
{
	int		i;
	char	**env;

	i = -1;
	while (envp[++i])
		;
	env = alloc().calloc(sizeof(char *) * (i + 1));
	if (!env)
		return (NULL);
	i = -1;
	while (envp[++i])
	{
		if (!string().strncmp(envp[i], "SHLVL=", 6))
			env[i] = shell_lvl(envp[i] + 6);
		else
			env[i] = string().strdup(envp[i]);
		if (!env[i])
		{
			alloc().free_matrix((void **)env);
			return (NULL);
		}
	}
	return (env);
}
