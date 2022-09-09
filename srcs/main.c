/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 20:59:45 by mtavares          #+#    #+#             */
/*   Updated: 2022/09/08 22:33:05 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(void)
{
	char	*str;

	while (1)
	{
		str = readline("MMshell>");
		printf("%lu\n", __str__().atoi(str));
		free(str);
	}
}
