/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 22:11:35 by mtavares          #+#    #+#             */
/*   Updated: 2022/10/29 22:25:42 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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

int	deal_with_non_existing_var(t_command *cmd, int i, char **envp)
{
	char	**tmp;
	int		j;

	tmp = envp;
	envp = alloc().calloc(length(envp));
	if (!envp)
	{
		envp = tmp;
		return (255);
	}
	j = -1;
	while (tmp[++j])
		envp[j] = tmp[j];
	free(tmp);
	envp[j] = cmd->args[i];
	return (0);
}

int	have_var(char *str, char **envp)
{
	int	i;

	i = -1;
	while (envp[++i])
		if (!string().strncmp(str, envp[i], string().len(str, '=')))
			return (i);
	return (-1);
}
