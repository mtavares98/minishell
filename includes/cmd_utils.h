/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 21:06:54 by mtavares          #+#    #+#             */
/*   Updated: 2022/09/25 18:08:07 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_UTILS_H
# define CMD_UTILS_H

# include <stdlib.h>
# include "allocs.h"
# include "cmd.h"
# include "str.h"

t_command	*cmdadd(char *path, char **split);
t_command	*new_node(char *path, char **split);
t_command	*cmdget(int i);
void		cmdremove(int i);
t_command	**cmd(void);

#endif
