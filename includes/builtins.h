/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 00:20:30 by mtavares          #+#    #+#             */
/*   Updated: 2023/01/26 00:15:31 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "cmd.h"
# include "str.h"
# include "env.h"
# include <unistd.h>
# include <stdio.h>

int		unset(t_command *cmd, t_env *env);
int		export(int out, t_command *cmd, t_env *env);
int		cd(t_command *cmd, t_env *env);
int		env(t_command *cmd, char **envp, int out);
int		exit_func(t_command **cmd, t_env *env);
int		echo(t_command *cmd, int out);
int		pwd(int out);
void	print_exp(int out, char **envp);
int		set_var(t_command *cmd);
int		print_error(t_command *cmd, int status, char *str);
int		deal_with_non_existing_var(t_command *cmd, int i, t_env *env);
int		have_var(char *str, char **envp);
int		length(char **envp);
int		is_nbr(char *s);
int		is_valid(char *str);

#endif
