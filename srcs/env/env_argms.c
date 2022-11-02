/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_argms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 22:54:18 by mgranate          #+#    #+#             */
/*   Updated: 2022/11/02 23:25:05 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// É preciso ainda retirar as aspas dos argumentos antes de os imprimir.
void	env_arg(t_command *cmd)
{
	int	i;

	i = 0;
	while(cmd->args[++i])
	{
		if(!string().strchr(cmd->args[i], '='))
		{
			printf("env: ‘%s’: No such file or directory\n", cmd->args[i]);
			return ;
		}
	}
	i = 0;
	print_env();
	while (cmd->args[++i])
		printf("%s\n", cmd->args[i]);
}