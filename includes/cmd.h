/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 21:08:39 by mtavares          #+#    #+#             */
/*   Updated: 2022/09/18 00:03:55 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_H
# define CMD_H

typedef struct s_command		t_command;
typedef struct s_cmdfunc		t_cmdfunc;

struct s_cmdfunc
{
	t_command	*(*add)(char *path, char **args);
	t_command	*(*get)(int i);
	void		(*remove)(int i);
};

struct s_command
{
	char		*path;
	char		**args;
	int			ready;
	t_command	*next;
};

t_command	**this(t_command **cmd);
t_command	**command(void);
t_cmdfunc	cmdfunc(void);

#endif
