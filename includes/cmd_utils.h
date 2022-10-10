/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 21:06:54 by mtavares          #+#    #+#             */
/*   Updated: 2022/10/01 15:41:13 by mtavares         ###   ########.fr       */
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
int			list_size_cmd(void);
t_command	**cmd(void);

#endif
