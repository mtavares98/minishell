/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 01:11:48 by mtavares          #+#    #+#             */
/*   Updated: 2022/11/03 00:26:51 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "allocs.h"

typedef struct s_env		t_env;

struct s_env
{
	char	**env;
	int		**pipe;
	int		status;
};

t_env	*this_env(void);
char	**create_env(char **envp);
int		handle_env(t_command *cmd, char **envp);
void	free_memory(t_command **cmd, t_env *env);
void	env_arg(t_command *cmd, t_env *env);
void	print_env(t_env *env);

#endif
