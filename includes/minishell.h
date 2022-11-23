/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:44:38 by mtavares          #+#    #+#             */
/*   Updated: 2022/11/23 01:03:48 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include "str.h"
# include "allocs.h"
# include "execution.h"
# include "cmd.h"
# include "arguments.h"
# include "env.h"
# include "expander.h"

void	printlist(t_command *vars, t_env *env);
int		check_expander(char **split, t_env *env);

#endif
