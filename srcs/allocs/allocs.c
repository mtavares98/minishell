/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 23:45:25 by mtavares          #+#    #+#             */
/*   Updated: 2022/09/17 00:16:52 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/allocs_utils.h"

void	free_matrix(void **matrix)
{
	int	i;

	i = -1;
	while (matrix[++i])
	{
		free(matrix[i]);
		(create_counter())->frees++;
	}
	free(matrix);
	(create_counter())->frees++;
}

void	free_array(void *array)
{
	free(array);
	(create_counter())->frees++;
}

static void	ft_bzero(void *s, size_t n)
{
	char	*str;
	size_t	i;

	str = s;
	i = -1;
	while (++i < n)
		str[i] = 0;
}

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
	(create_counter())->mallocs++;
	return (ptr);
}

t_allocs	alloc(void)
{
	static t_allocs	allocs = {
		ft_calloc, free_matrix, free_array
	};

	return (allocs);
}
