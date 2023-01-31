/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 17:51:10 by mtavares          #+#    #+#             */
/*   Updated: 2023/01/31 14:11:16 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

char	*getpath(char **envp)
{
	char	*path;
	int		i;

	path = NULL;
	i = -1;
	while (envp[++i])
	{
		if (!string().strncmp(envp[i], "PATH=", 5))
		{
			path = envp[i];
			break ;
		}
	}
	return (path);
}

int	exec_builtins(int out, t_command **cmd)
{
	if (!string().strncmp((*cmd)->path, "echo", 5))
		return (echo(*cmd, out));
	else if (!string().strncmp((*cmd)->path, "cd", 3))
		return (cd(*cmd, this_env()));
	else if (!string().strncmp((*cmd)->path, "pwd", 4))
		return (pwd(out));
	else if (!string().strncmp((*cmd)->path, "export", 7))
		return (export(out, *cmd, this_env()));
	else if (!string().strncmp((*cmd)->path, "unset", 6))
		return (unset(*cmd, this_env()));
	else if (!string().strncmp((*cmd)->path, "env", 4))
		return (env(*cmd, this_env()->env, out));
	else if (!string().strncmp((*cmd)->path, "exit", 5))
		return (exit_func(cmd, this_env()));
	else
		return (0);
}
