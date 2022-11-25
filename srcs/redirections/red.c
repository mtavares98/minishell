/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:23:13 by mtavares          #+#    #+#             */
/*   Updated: 2022/11/25 18:17:51 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/red_utils.h"

/*
	Order heredoc, output files, input files
*/

/*
	1st Search for all heredocs and fill them
		if ther's more input files delete them
	2nd if there's correnpondent output or input file close it to open again
		Open all output or input files that aren't output files
	4th Do that for all cmd nodes
*/

t_redfunc	redfunc(void)
{
	static t_redfunc	redfunc = {
		redadd, redget, redremove
	};

	return (redfunc);
}

t_red	**this_red(void)
{
	static t_red	io;

	return (&io);
}
