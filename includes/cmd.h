/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 21:08:39 by mtavares          #+#    #+#             */
/*   Updated: 2022/09/25 18:08:51 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_H
# define CMD_H

typedef struct s_command		t_command;
typedef struct s_cmdfunc		t_cmdfunc;
typedef struct s_tmp			t_tmp;

struct s_cmdfunc
{
	t_command	*(*add)(char *path, char **split);
	t_command	*(*get)(int i);
	void		(*remove)(int i);
};

struct s_tmp
{
	char		*args;
	t_tmp		*next;
};

struct s_command
{
	char		*path;
	char		**args;
	int			ready;
	t_command	*next;
};

t_command	**this(void);
t_cmdfunc	cmdfunc(void);
int			list_size(char **split);

#endif
