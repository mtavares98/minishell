/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocs_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 23:46:24 by mtavares          #+#    #+#             */
/*   Updated: 2022/09/17 01:24:35 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALLOCS_UTILS_H
# define ALLOCS_UTILS_H

# include <stdlib.h>
# include "allocs.h"

void		free_matrix(void **matrix);
void		free_array(void *array);
void		*ft_calloc(size_t size);

#endif
