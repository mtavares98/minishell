/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:44:38 by mtavares          #+#    #+#             */
/*   Updated: 2022/11/23 14:03:28 by mtavares         ###   ########.fr       */
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

void	printlist(t_command *vars);
int		check_expander(char **split, t_env *env);

#endif
