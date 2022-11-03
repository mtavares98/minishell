/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:55:41 by mtavares          #+#    #+#             */
/*   Updated: 2022/11/03 00:27:47 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_env	*this_env(void)
{
	static t_env	env;

	return (&env);
}

void	print_env(t_env *env)
{
	int	i;

	i = -1;
	while (env->env[i])
		printf("%s\n", env->env[i]);
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

int	export_handler(t_command *cmd, t_env *env)
{
	(void)cmd;
	(void)env;
	
	//if (!cmd->args[1])
	//	print_export();
	return (0);
}

int	env_handler(t_command *cmd, t_env *env)
{
	if (!cmd->args[1])
		print_env(env);
	else
		env_arg(cmd, env);
	return (0);
}
int	unset_handler(t_command *cmd, t_env *env)
{
	(void)cmd;
	(void)env;
	return(0);
}

int	handle_env(t_command *cmd, char **envp)
{
	t_env	*env;
	
	env = this_env();
	env->env = create_env(envp);
	//Dont forget to handle the exp and env when tey have quotes, like so: "export" or "env"
	if (!string().strncmp(cmd->args[0], "export", 5))
		export_handler(cmd, env);
	if(!string().strncmp(cmd->args[0], "unset", 4))
		unset_handler(cmd, env);
	if (!string().strncmp(cmd->args[0], "env", 2))
		env_handler(cmd, env);
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