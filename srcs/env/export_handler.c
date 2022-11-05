/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 23:33:30 by mgranate          #+#    #+#             */
/*   Updated: 2022/11/05 00:03:13 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	import_variable(t_command *cmd, char *env, int i)
{
	char	*tmp;
	int		j;
	
	j = 0;
	while (cmd->args[++j])
	{
		tmp = string().substr(cmd->args[j], 0, string().len(cmd->args[j], '=') - 1);
		remove_quotes(tmp);
		if (string().contains(env[i], tmp, string().len(tmp, -1)))
		{
			env[i] = string().
		}
		alloc().free_array(tmp);
	}	
}

int	export_values(t_command *cmd, t_env *env)
{
	int	i;

	i = -1;
	while (env->env[i])
	{
		import_variable(cmd, env->env, i);
	}	
	return (0);
}

// Enquanto env existir
// Vou iterar as variaveis ambientes
// Em cada iteracao verificar se ja existe uma variavel igual
// Caso exista substituir o valor da mesma
// Caso nao exista adicionar a variavel no final da lista
