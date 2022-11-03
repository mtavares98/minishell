/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 01:59:46 by mgranate          #+#    #+#             */
/*   Updated: 2022/11/03 02:07:31 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	**create_env(char **envp, int valid)
{
	int		i;
	char	**env;
	int		ct;

	ct = 0;
	i = -1;
	while (envp[++i])
		ct++;
	if (valid >= 0)
		ct--;
	env = alloc().calloc(sizeof(char *) * (ct + 1));
	if (!env)
		return (NULL);
	i = -1;
	ct = 0;
	while (envp[++i])
	{
		if (i != valid)
		{
			env[ct] = string().strdup(envp[i]);
			if (!env[ct])
			{
				alloc().free_matrix((void **)env);
				return (NULL);
			}
			ct++;
		}
	}
	return (env);
}

void	print_env(t_env *env)
{
	int	i;

	i = -1;
	while (env->env[++i])
		printf("%s\n", env->env[i]);
}

void	print_export(char **envp)
{
	//int		i;
	int		nb;
	//char	**tmp_env;

	//i = -1;
	while (envp[nb])
		nb++;
	//tmp_env = create_env(envp);
}

