/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 17:45:22 by mtavares          #+#    #+#             */
/*   Updated: 2023/01/26 00:09:03 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/builtins.h"

int	is_valid(char *str)
{
	int	i;

	i = -1;
	while (str[++i] && str[i] != '=')
	{
		if (i == 0 && !((str[i] >= 'a' && str[i] <= 'z') || \
		(str[i] >= 'A' && str[i] <= 'Z')))
			return (0);
		if (i && !string().ft_isalnum(str[i]))
			return (0);
	}
	return (1);
}

int	print_error(t_command *cmd, int status, char *str)
{
	write(2, "MMShell: ", 9);
	write(2, cmd->args[0], string().len(cmd->args[0], -1));
	write(2, ": '", 3);
	write(2, cmd->args[1], string().len(cmd->args[1], -1));
	write(2, "'", 1);
	write(2, str, string().len(str, -1));
	return (status);
}

static char	*get_var(char **env, char *key)
{
	int		i;
	char	*value;

	i = -1;
	while (env[++i])
	{
		if (!string().strncmp(key, env[i], string().len(key, -1)))
		{
			value = string().strdup(env[i] + string().len(env[i], '='));
			return (value);
		}
	}
	return (NULL);
}

int	set_var(t_command *cmd)
{
	char	**tmp;
	char	*value;

	value = get_var(this_env()->env, "HOME=");
	if (!value)
		return (print_error(cmd, 1, "HOME not set"));
	tmp = cmd->args;
	cmd->args = alloc().calloc(sizeof(char *) * (3));
	if (!cmd->args)
		return (2);
	cmd->args[0] = tmp[0];
	cmd->args[1] = value;
	alloc().free_array(tmp);
	return (0);
}
