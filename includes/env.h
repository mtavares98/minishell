/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 01:11:48 by mtavares          #+#    #+#             */
/*   Updated: 2023/01/25 22:32:16 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "allocs.h"
# include "cmd.h"

typedef struct s_env		t_env;

struct s_env
{
	char			**env;
	unsigned char	status;
};

t_env	*this_env(void);
char	**create_env(char **envp);
void	free_memory(t_command **cmd);

#endif
