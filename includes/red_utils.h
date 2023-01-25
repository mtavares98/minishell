/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:24:06 by mtavares          #+#    #+#             */
/*   Updated: 2023/01/25 16:38:45 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RED_UTILS_H
# define RED_UTILS_H

# include "allocs.h"
# include "cmd.h"

void	remove_node_red(t_red *node);
void	remove_by_reference(t_red *remove, t_red **begin);
t_red	*red_add(char *file, int is_double, int is_output, t_red **begin);
t_red	*red_get(int i, t_red *red);
void	red_remove(int i, t_red **begin);

#endif
