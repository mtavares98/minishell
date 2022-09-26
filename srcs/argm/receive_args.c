/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   receive_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 16:52:55 by mgranate          #+#    #+#             */
/*   Updated: 2022/09/26 15:25:31 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"


int	receive_args(char *str)
{
	argm_handler(str);
	//printlist(*this());
	//if ((*this())->path)
	//	alloc().free_array((void *)(*this())->path);
	//if ((*this())->args)
	//	alloc().free_matrix((void *)(*this())->args);
	//if ((*this()))
	//	alloc().free_array((void *)(*this()));
	return (1);
}
