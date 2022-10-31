/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 21:48:18 by mtavares          #+#    #+#             */
/*   Updated: 2022/10/25 13:56:41 by mtavares         ###   ########.fr       */
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

struct s_exec
{
	int	*pid;
	int	**pfd;
	int	i;
};

char	**create_env(char **envp);
int		**get_pipesfd(int num_cmd);
char	*get_complete_path(char *cmd, char **path);
char	*getpath(char **envp);
int		prep_exec(t_command **cmd, char **envp);
int		execution(t_command **cmd, char **envp);
int		check_files(t_command **cmd, char *path);

#endif
