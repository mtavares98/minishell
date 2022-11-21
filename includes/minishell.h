/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:44:38 by mtavares          #+#    #+#             */
/*   Updated: 2022/11/21 19:56:59 by mtavares         ###   ########.fr       */
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

void	printlist(t_command *vars, t_env *env);

#endif
