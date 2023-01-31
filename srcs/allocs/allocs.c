/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:40:38 by mtavares          #+#    #+#             */
/*   Updated: 2023/01/31 14:02:44 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "allocs_utils.h"

/*
	It will free a matrix
*/
void	free_matrix(void **matrix)
{
	int	i;

	i = -1;
	if (!matrix)
		return ;
	while (matrix[++i])
	{
		free(matrix[i]);
		counter()->frees++;
	}
	free(matrix);
	matrix = NULL;
	counter()->frees++;
}

/*
	It will free an array
*/

void	free_array(void *array)
{
	if (!array)
		return ;
	free(array);
	array = NULL;
	array = NULL;
	counter()->frees++;
}

/*
	Sets n bytes of a void pointer to 0
*/
static void	*ft_bzero(void *s, size_t n)
{
	char	*str;
	size_t	i;

	str = s;
	i = -1;
	while (++i < n)
		str[i] = 0;
	return (s);
}

/*
	Allocates a memory a sets all bytes to 0
*/
void	*ft_calloc(size_t size)
{
	void	*ptr;

	if (size == 0)
		return (NULL);
	ptr = malloc(size);
	if (!ptr)
		return (ptr);
	ptr = ft_bzero(ptr, size);
	(counter())->mallocs++;
	return (ptr);
}

/*
	Calls a struct with functions for allocation and deallocates memory
*/

t_allocs	alloc(void)
{
	static t_allocs	allocs = {
		ft_calloc, free_matrix, free_array
	};

	return (allocs);
}
