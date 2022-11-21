/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 22:11:35 by mtavares          #+#    #+#             */
/*   Updated: 2022/11/21 19:58:03 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/builtins.h"

int	is_nbr(char *s)
{
	int	i;

	i = -1;
	while (string().ft_isspace(s[++i]))
		;
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (!string().isdig(s[i]))
		return (0);
	while (string().isdig(s[i]))
		i++;
	while (string().ft_isspace(s[i]))
		i++;
	if (s[i])
		return (0);
	return (1);
}

int	length(char **envp)
{
	int	i;

	i = -1;
	while (envp[++i])
		;
	return (i);
}

int	deal_with_non_existing_var(t_command *cmd, int i, t_env *env)
{
	char	**tmp;
	int		j;

	tmp = env->env;
	env->env = alloc().calloc((length(env->env) + 2) * sizeof(char *));
	if (!env->env)
	{
		env->env = tmp;
		return (255);
	}
	j = -1;
	while (tmp[++j])
		env->env[j] = tmp[j];
	alloc().free_array((void *)tmp);
	env->env[j] = string().strdup(cmd->args[i]);
	return (0);
}

int	have_var(char *str, char **envp)
{
	int	i;

	i = -1;
	while (envp[++i])
		if (!string().strncmp(str, envp[i], string().len(envp[i], '=') - 1))
			return (i);
	return (-1);
}

void	print_exp(int out, char **envp)
{
	int	i;
	int	len;

	i = -1;
	while (envp[++i])
	{
		len = string().len(envp[i], '=');
		write(out, "declare -x ", 11);
		write(out, envp[i], len);
		if (envp[i][len - 1] != '=')
			write(out, "=", 1);
		write(out, "\"", 1);
		if (envp[i][len])
			write(out, envp[i] + len, string().len(envp[i] + len, -1));
		write(out, "\"\n", 2);
	}
}
