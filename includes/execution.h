/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 21:48:18 by mtavares          #+#    #+#             */
/*   Updated: 2022/09/18 14:57:37 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <errno.h>
# include "get_next_line.h"
# include "str.h"
# include "cmd.h"

typedef struct s_exec			t_exec;
typedef struct s_redirection	t_redirection;

struct s_exec
{
	int	*pid;
	int	**pfd;
	int	i;
};

struct s_redirection
{
	char	*limiter;
	char	*infile;
	int		infd;
	int		is_trunc;
	char	*outfile;
	int		outfd;
};

char	*get_complete_path(char *cmd, char **path);
char	*getpath(char **envp);
int		**pipesfd_or_processid(int nbcmd);
int		exec_main(t_command **command, t_redirection *redirection, char **envp);

#endif
