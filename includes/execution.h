/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 21:48:18 by mtavares          #+#    #+#             */
/*   Updated: 2023/01/31 14:09:58 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <stdio.h>
# include "str.h"
# include "cmd.h"
# include "env.h"

typedef struct s_exec	t_exec;

struct s_exec
{
	int	*pid;
	int	**pfd;
	int	i;
};

int		fill_heredoc(int fd, char *delimiter);
int		check_heredoc(t_red *io);
int		get_num_cmd(t_command *cmd);
int		print_error_cmd(int status, char path_exists, char *file);
void	update_status(t_env *env);
void	close_fd_exeption(t_command **cmd, int in, int out);
char	*get_complete_path(char *cmd, char **path);
int		is_builtin(char *cmd);
char	*getpath(char **envp);
int		exec_builtins(int out, t_command **cmd);
void	close_fd(int *in, int *out);
int		prep_exec(t_command **cmd);
int		execution(t_command **cmd);
int		check_files(t_command *cmd, char *path);

#endif
