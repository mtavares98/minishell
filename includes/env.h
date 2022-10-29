/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 01:11:48 by mtavares          #+#    #+#             */
/*   Updated: 2022/10/29 15:19:15 by mtavares         ###   ########.fr       */
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
	char	**str;
};

t_env	*this_env(void);
char	**create_env(char **envp);
void	free_memory(t_command **cmd, t_env *env);

#endif
