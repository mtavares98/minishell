/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:47:43 by mtavares          #+#    #+#             */
/*   Updated: 2022/10/25 16:48:05 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	cd(t_command *cmd, char **envp)
{
}

int	export(t_command *cmd, char **envp)
{
	char	**tmp;
	int		arg;
	int		i;
	int		j;

	i = 0;
	while (cmd->args[++i])
	{
		j = string().len(cmd->args[i], '=') - 1;
		if (cmd->args[i][j] == '=')
		{
			j = have_var(cmd->args[i], envp);
			if (j != -1)
			{
				free(envp[j]);
				envp[j] = string().strdup(cmd->args[i]);
			}
			else
				if (deal_with_non_existing_var(cmd, i, envp))
					return (255);
		}
	}
	return (0);
}

int	env(t_command *cmd, char **envp)
{
	int	i;

	i = -1;
	while (cmd->args[++i])
		;
	if (i != 1)
		return (1);
	i = -1;
	while (envp[++i])
		printf("%s\n", envp[i]);
	return (0);
}

int	pwd(void)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	if (!pwd)
		return (1);
	printf("%s\n", pwd);
	free(pwd);
	return (0);
}

int	echo(t_command *cmd)
{
	int	i;

	i = 0 + (!string().strncmp(cmd->args[1], '-n', 3));
	while (cmd->args[++i])
	{
		printf("%s", cmd->args[i]);
		if (cmd->args[i + 1])
			printf(" ");
	}
	return (0);
}
