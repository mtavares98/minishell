/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:55:41 by mtavares          #+#    #+#             */
/*   Updated: 2022/11/02 23:46:33 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	**g_env;

t_env	*this_env(void)
{
	static t_env	env;

	return (&env);
}

char	**create_env(char **envp)
{
	int		i;

	i = -1;
	while (envp[++i])
		;
	g_env = alloc().calloc(sizeof(char *) * (i + 1));
	if (!g_env)
		return NULL;
	i = -1;
	while (envp[++i])
	{
		g_env[i] = string().strdup(envp[i]);
		if (!g_env[i])
		{
			alloc().free_matrix((void **)g_env);
			return NULL;
		}
	}
	return (g_env);
}

void	print_env()
{
	int	i;

	i = -1;
	while (g_env[++i])
		printf("%s\n", g_env[i]);
}

void	print_export(char **envp)
{
	//int		i;
	int		nb;
	//char	**tmp_env;

	//i = -1;
	while (envp[nb])
		nb++;
	//tmp_env = create_env(envp);
}

int	export_handler(t_command *cmd)
{
	(void)cmd;
	//if (!cmd->args[1])
	//	print_export();
	return (0);
}

int	env_handler(t_command *cmd)
{
	if (!cmd->args[1])
		print_env();
	else
		env_arg(cmd);
	return (0);
}

int	handle_env(t_command *cmd)
{
	(void)cmd;
	//Dont forget to handle the exp and env when tey have quotes, like so: "export" or "env"
	if (!string().strncmp(cmd->args[0], "export", 5))
		export_handler(cmd);
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
// ENV counts every single argument that has an = sign, no matter the position of it
// If we use ENV with arguments like: env hello it sends a wrond command not
// ENV Edge Case: env = hello => No such file in directory error
// ENV Edge Case: env "=   hello" => Prints normaly
// ENV Only reads the last argm. If invalid all is invalid, if valid, only prints that one

// Unset which removes the variable, cant take as argument the "=", just the name raw
// Unset only works if you put the argument without the var name, like so: unset hello (var name is: hello=world)

//NOTA: DONT FORGE TO CLEAN ARRAY OF ENV VARS