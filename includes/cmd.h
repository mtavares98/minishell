/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 21:08:39 by mtavares          #+#    #+#             */
/*   Updated: 2022/11/23 19:23:55 by mgranate         ###   ########.fr       */
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
	int			(*size)(void);
};

struct s_tmp
{
	char		*args;
	t_tmp		*next;
};

// >> Append == 1
// > Append == 0
// << Heredoc == 1
// < Heredoc == 0
// < file1 cat > out1 > out2 > out3 => Outfile
// < file1 cat < file2 < file3 =>Infile 

struct s_command
{
	int			append;
	int			heredoc;
	int			outfd;
	int			infd;
	struct red	*out;
	struct red	*in;
	char		*path;
	char		**args;
	t_command	*next;
};

t_command	**this(void);
t_cmdfunc	cmdfunc(void);
int			list_size(char **split);

#endif
