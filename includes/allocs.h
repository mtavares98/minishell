/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocs.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 00:11:00 by mtavares          #+#    #+#             */
/*   Updated: 2022/09/17 01:24:23 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALLOCS_H
# define ALLOCS_H

# include <stdlib.h>

typedef struct s_allocs		t_allocs;
typedef struct s_counter	t_counter;

struct s_counter
{
	unsigned int	mallocs;
	unsigned int	frees;
};

struct s_allocs
{
	void	*(*calloc)(size_t nmemb, size_t size);
	void	(*free_matrix)(void **matrix);
	void	(*free_array)(void *array);
};

t_allocs	alloc(void);
t_counter	*create_counter(void);

#endif
