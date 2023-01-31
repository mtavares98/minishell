/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:23:13 by mtavares          #+#    #+#             */
/*   Updated: 2023/01/31 14:14:04 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "red_utils.h"

/*
	Order heredoc, output files, input files
*/

/*
	1st Search for all heredocs and fill them
		if ther's more input files delete them
	2nd if there's correspondent output or input file close it to open again
		Open all output or input files that aren't output files
	4th Do that for all cmd nodes
*/

t_redfunc	redfunc(void)
{
	static t_redfunc	redfunc = {
		red_add, red_get, red_remove, remove_by_reference
	};

	return (redfunc);
}

t_red	**this_red(t_red *red)
{
	static t_red	*io;

	if (red)
		io = red;
	return (&io);
}
