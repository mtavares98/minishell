/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 23:45:25 by mtavares          #+#    #+#             */
/*   Updated: 2022/09/17 01:33:24 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/allocs_utils.h"

/*
	It will free an matrix
*/
void	free_matrix(void **matrix)
{
	int	i;

	i = -1;
	while (matrix[++i])
	{
		free(matrix[i]);
		(counter())->frees++;
	}
	free(matrix);
	(counter())->frees++;
}

/*
	It will free an array
*/
void	free_array(void *array)
{
	free(array);
	(counter())->frees++;
}

/*
	Sets n bytes of a void pointer to 0
*/
static void	ft_bzero(void *s, size_t n)
{
	char	*str;
	size_t	i;

	str = s;
	i = -1;
	while (++i < n)
		str[i] = 0;
}

/*
	Allocs a memory a sets all bytes to 0
*/
void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*ptr;
	size_t	total;

	total = nmemb * size;
	if (nmemb == 0 || size == 0 || total / size != nmemb)
		return (NULL);
	ptr = malloc(total);
	if (!ptr)
		return (ptr);
	ft_bzero(ptr, total);
	(counter())->mallocs++;
	return (ptr);
}

/*
	Calls an struct with functions for allocation and deallocation of memory
*/

t_allocs	alloc(void)
{
	static t_allocs	allocs = {
		ft_calloc, free_matrix, free_array
	};

	return (allocs);
}
