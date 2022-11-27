/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 15:41:29 by mtavares          #+#    #+#             */
/*   Updated: 2022/11/27 23:02:41 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RED_H
# define RED_H

# include <unistd.h>
# include "str.h"
# include "cmd.h"
# include "get_next_line.h"

typedef struct s_red		t_red;
typedef struct s_redfunc	t_redfunc;

struct s_redfunc
{
	t_red	*(*add)(char *file, int is_double, int is_output);
	t_red	*(*get)(int i);
	void	(*remove)(int i);
};

/*
	>> Is_double == 1 && is_output == 1
	> Is_double == 0 && is_output == 1
	<< Is_double == 1 && is_output == 0
	< Is_double == 0 && is_output == 0
	File = name of the file or delimiter of heredoc
*/

struct s_red
{
	int		fd;
	int		is_double;
	int		is_output;
	char	*file;
	t_red	*next;
};

int			prep_heredoc(t_red *io);
int			prep_red(t_command **cmd);
t_red		**this_red(void);
t_redfunc	redfunc(void);

#endif
