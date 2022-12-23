/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:24:06 by mtavares          #+#    #+#             */
/*   Updated: 2022/12/23 17:37:39 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RED_UTILS_H
# define RED_UTILS_H

# include "allocs.h"
# include "cmd.h"

void	remove_node_red(t_red *node);
void	remove_by_reference(t_red *remove);
t_red	*redadd(char *file, int is_double, int is_output);
t_red	*redget(int i, t_red *red);
void	redremove(int i);
int		list_size_red(void);
t_red	**red(void);

#endif
