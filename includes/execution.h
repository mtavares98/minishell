/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 21:48:18 by mtavares          #+#    #+#             */
/*   Updated: 2022/10/29 23:34:40 by mtavares         ###   ########.fr       */
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
# include "env.h"

typedef struct s_exec			t_exec;

struct s_exec
{
	int	*pid;
	int	**pfd;
	int	i;
};

int		**get_pipesfd(int num_cmd);
char	*get_complete_path(char *cmd, char **path);
char	*getpath(char **envp);
int		exec_builtins(int out, t_command **cmd);
void	close_fd(int *in, int *out);
int		prep_exec(t_command **cmd);
int		execution(t_command **cmd);
int		check_files(t_command **cmd, char *path);

#endif
