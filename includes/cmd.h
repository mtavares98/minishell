/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 21:08:39 by mtavares          #+#    #+#             */
/*   Updated: 2022/11/27 19:04:13 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_H
# define CMD_H

# include "red.h"

typedef struct s_command		t_command;
typedef struct s_red			t_red;
typedef struct s_cmdfunc		t_cmdfunc;
typedef struct s_tmp			t_tmp;

struct s_cmdfunc
{
	t_command	*(*add)(char *path, char **split);
	t_command	*(*get)(int i);
	void		(*remove)(int i);
	int			(*size)(void);
};

struct s_tmp
{
	char		*args;
	t_tmp		*next;
};

struct s_command
{
	t_red		*io;
	char		*path;
	char		**args;
	t_command	*next;
};

t_command	**this(void);
t_cmdfunc	cmdfunc(void);
int			list_size(char **split);

#endif
