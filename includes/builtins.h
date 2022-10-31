/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 00:20:30 by mtavares          #+#    #+#             */
/*   Updated: 2022/10/29 23:13:30 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "cmd.h"
# include "str.h"
# include "env.h"
# include <unistd.h>
# include <stdio.h>

int	is_nbr(char *s);
int	env(t_command *cmd, char **envp, int out);
int	exit_func(t_command **cmd, t_env *env, int out);
int	echo(t_command *cmd, int out);
int	pwd(int out);

#endif
