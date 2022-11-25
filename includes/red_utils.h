/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:24:06 by mtavares          #+#    #+#             */
/*   Updated: 2022/11/25 18:08:00 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RED_UTILS_H
# define RED_UTILS_H

# include "allocs.h"
# include "red.h"

t_red	*redadd(char *file, int is_double, int is_output);
t_red	*redget(int i);
void	redremove(int i);
int		list_size_red(void);
t_red	**red(void);

#endif
