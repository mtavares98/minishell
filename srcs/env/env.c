/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:55:41 by mtavares          #+#    #+#             */
/*   Updated: 2022/10/29 02:25:14 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_env	*this_env(void)
{
	static t_env	env;

	return (&env);
}

char	**create_env(char **envp)
{
	int		i;
	char	**env;

	i = -1;
	while (envp[++i])
		;
	env = alloc().calloc(sizeof(char *) * (i + 1));
	if (!env)
		return (NULL);
	i = -1;
	while (envp[++i])
	{
		env[i] = string().strdup(envp[i]);
		if (!env[i])
		{
			alloc().free_matrix((void **)env);
			return (NULL);
		}
	}
	return (env);
}

// Use Malloc to create an array that's gonna take the env. variables
// extern char **g_environ forma de declarar uma varaivel global que pode estar em varios ficheiros, tentar perceber a aplicação prática disto
// Export == Export's variables or modifies existing env variables
// ENV == Prints out all variables with a value, meaning strings that contain an = sign
// Unset which removes the variable, cant take as argument the "=", just the name raw
// Export without any arguments prints the list in asci order
