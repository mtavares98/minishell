/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:55:41 by mtavares          #+#    #+#             */
/*   Updated: 2022/10/25 17:45:15 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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

void	print_export(char **envp)
{
	int		i;
	int		nb;
	char	**tmp_env;

	i = -1;
	while (envp[nb])
		nb++;
	tmp_env = create_env(envp);
	while (i < nb)
	{
		
	}
}

int	export_handler(t_command *cmd, char **envp)
{
	if (!cmd->args[1])
		print_export(envp);
	return (0);
}


int	env_handler(t_command *cmd)
{
	return (0);
}

int	handle_env(char **envp, t_command *cmd)
{
	(void)cmd;
	(void)envp;
	//Dont forget to handle the exp and env when tey have quotes, like so: "export" or "env"
	if (!string().strncmp(cmd->args[0], "export", 5))
		export_handler(cmd, envp);
	if (!string().strncmp(cmd->args[0], "env", 2))
		env_handler(cmd);
	return (0);	
}



// extern char **g_environ forma de declarar uma varaivel global que pode estar em varios ficheiros, tentar perceber a aplicação prática disto
// Export == Export's variables or modifies existing env variables
// Export without any arguments prints the list in asci order 
// Export can add a variable without a value, but that var will only be printed if you use export and not with Env == IT WILL PRINT WITH 
// QUOTES the value of the variable, like so: A="AB" and it will also print the: "declare -x" before the variable 

// ENV == Prints out all variables with a value, meaning strings that contain an = sign
// ENV with arguments like: hello=this prints out that arg in the last seccion, but it does not add it
// If we use ENV with arguments like: env hello it sends a wrond command not

// Unset which removes the variable, cant take as argument the "=", just the name raw
// Unset only works if you put the argument without the var name, like so: unset hello (var name is: hello=world)

//NOTA: DONT FORGE TO CLEAN ARRAY OF ENV VARS

