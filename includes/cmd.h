/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 21:08:39 by mtavares          #+#    #+#             */
/*   Updated: 2023/01/06 15:49:47 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_H
# define CMD_H

# include <unistd.h>
# include <fcntl.h>
# include "str.h"
# include "get_next_line.h"

typedef struct s_red			t_red;
typedef struct s_command		t_command;
typedef struct s_redfunc		t_redfunc;
typedef struct s_cmdfunc		t_cmdfunc;

/*
	>> Is_double == 1 && is_output == 1
	> Is_double == 0 && is_output == 1
	<< Is_double == 1 && is_output == 0
	< Is_double == 0 && is_output == 0
	File = name of the file or delimiter of heredoc
*/

struct s_cmdfunc
{
	t_command	*(*add)(char *path, char **split);
	t_command	*(*get)(int i);
	void		(*remove)(int i);
	int			(*size)(void);
};

struct s_command
{
	int			outfd;
	int			infd;
	t_red		*io;
	char		*path;
	char		**args;
	t_command	*next;
};

struct s_redfunc
{
	t_red	*(*add)(char *file, int is_double, int is_output, t_red **begin);
	t_red	*(*get)(int i, t_red *red);
	void	(*remove)(int i, t_red **begin);
	void	(*remove_referenece)(t_red *remove, t_red **begin);
};

struct s_red
{
	int		fd;
	int		is_double;
	int		is_output;
	char	*file;
	t_red	*next;
};

t_command	**this(void);
t_cmdfunc	cmdfunc(void);
int			list_size(char **split);
int			prep_heredoc(t_red *io);
int			prep_red(t_command **cmd);
t_red		**this_red(t_red *red);
t_redfunc	redfunc(void);
int			check_red(t_red *red, t_command *cmd);

#endif
