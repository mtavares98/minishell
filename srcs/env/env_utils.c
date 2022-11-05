/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 01:59:46 by mgranate          #+#    #+#             */
/*   Updated: 2022/11/04 23:22:43 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	**create_env(char **envp, int valid)
{
	int		i;
	char	**env;
	int		ct;

	i = -1;
	while (envp[++i])
		;
	if (valid >= 0)
		i--;
	env = alloc().calloc(sizeof(char *) * (i + 1));
	if (!env)
		return (NULL);
	i = -1;
	ct = -1;
	while (envp[++i])
	{
		if (i != valid)
		{
			env[++ct] = string().strdup(envp[i]);
			if (!env[ct])
			{
				alloc().free_matrix((void **)env);
				return (NULL);
			}
		}
	}
	return (env);
}

int	print_env_aux(char **env, t_command *cmd, int i)
{
	char	*tmp;
	int		j;
	int		ctr;

	j = 0;
	ctr = 0;
	while (cmd->args[++j])
	{
		tmp = string().substr(cmd->args[j], 0, string().len(cmd->args[j], '=') - 1);
		if (string().contains(env[i], tmp, string().len(tmp, -1)))
		{
			printf("%s\n", remove_quotes(cmd->args[j]));
			ctr = 1;
		}
		alloc().free_array(tmp);
	}
	return(ctr);
}

void	print_env(char **env, t_command *cmd)
{
	int		i;
	
	i = -1;
	while (env[++i])
	{
		if (string().strchr(env[i], '='))
		{
			if (cmd->args[1])
			{
				if (!print_env_aux(env, cmd, i))
					printf("%s\n", env[i]);	
			}
			else
				printf("%s\n", env[i]);
		}
	}
}

void	print_export(char **envp)
{
	//int		i;
	int		nb;
	//char	**tmp_env;
	nb = 0;
	//i = -1;
	while (envp[nb])
	{
		printf("%s\n", envp[nb]);
		nb++;
	}
	//tmp_env = create_env(envp);
}

