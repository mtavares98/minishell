/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 21:06:54 by mtavares          #+#    #+#             */
/*   Updated: 2022/09/17 23:38:32 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_UTILS_H
# define CMD_UTILS_H

# include <stdlib.h>
# include "allocs.h"
# include "cmd.h"
# include "str.h"

t_command	*cmdadd(char *path, t_tmp_arg *args);
t_command	*new_node(char *path, t_tmp_arg *argms);
t_command	*cmdget(int i);
void		cmdremove(int i);
t_command	**cmd(void);

#endif
