/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 23:33:30 by mgranate          #+#    #+#             */
/*   Updated: 2022/11/09 01:18:35 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	replace_env(char *tmp, t_env *env, int j)
{
	alloc().free_array(env->env[j]);
	env->env[j] = string().strdup(tmp);
}

int	export_values(t_command *cmd, t_env *env)
{
	char	*tmp;
	int		i;
	int		j;
	int		ct;
	
	i = 0;
	while (cmd->args[++i])
	{
		ct = 0;
		j = -1;
		while (env->env[++j])
		{
			tmp = remove_quotes(cmd->args[i]);
			if (string().contains(env->env[j], string().substr(tmp, 0, string().len(tmp, '=')), string().len(tmp, -1)))
			{
				printf("DEBUGG\n");
				replace_env(tmp, env, j);
				ct++;
			}
		}
		if (ct == 0)
			deal_with_non_existing_var(tmp, env->env);
	}
	return (0);
}

// Enquanto env existir
// Vou iterar as variaveis ambientes
// Em cada iteracao verificar se ja existe uma variavel igual
// Caso exista substituir o valor da mesma
// Caso nao exista adicionar a variavel no final da lista
