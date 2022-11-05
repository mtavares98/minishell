/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 17:51:10 by mtavares          #+#    #+#             */
/*   Updated: 2022/11/05 23:41:33 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/execution.h"
#include "../../includes/builtins.h"

static void	close_pipes(int **pipe_fd, int i)
{
	int	j;

	j = -1;
	while (++j < i)
	{
		close(pipe_fd[j][0]);
		close(pipe_fd[j][1]);
	}
}

static int	start_pipes(int **pipe_fd)
{
	int	i;

	i = -1;
	while (pipe_fd[++i])
	{
		if (pipe(pipe_fd[i]) == -1)
		{
			perror("pipe");
			close_pipes(pipe_fd, i + 1);
			return (1);
		}
	}
	return (0);
}

int	**get_pipesfd(int num_cmd)
{
	int	i;
	int	**pipe_fd;

	pipe_fd = alloc().calloc((num_cmd) * sizeof(int *));
	if (!pipe_fd)
		return (NULL);
	i = -1;
	while (++i < num_cmd - 1)
	{
		pipe_fd[i] = alloc().calloc(2 * sizeof(int));
		if (!pipe_fd[i])
		{
			alloc().free_matrix((void **)pipe_fd);
			return (NULL);
		}
	}
	if (start_pipes(pipe_fd))
		alloc().free_matrix((void **)pipe_fd);
	return (pipe_fd);
}

char	*getpath(char **envp)
{
	char	*path;
	int		i;

	path = NULL;
	i = -1;
	while (envp[++i])
	{
		if (!string().strncmp(envp[i], "PATH=", 5))
		{
			path = envp[i];
			break ;
		}
	}
	return (path);
}

int	exec_builtins(int out, t_command **cmd)
{
	if (!string().strncmp((*cmd)->path, "echo", 5))
		return (echo(*cmd, out));
	/* else if (!string().strncmp(cmd->path, "cd", 3))
		cd(cmd, envp); */
	else if (!string().strncmp((*cmd)->path, "pwd", 4))
		return (pwd(out));
	/* else if (!string().strncmp(cmd->path, "export", 7))
		export(cmd, envp);
	else if (!string().strncmp(cmd->path, "unset", 6))
		unset(cmd, envp); */
	else if (!string().strncmp((*cmd)->path, "env", 4))
		return (env(*cmd, this_env()->env, out));
	else if (!string().strncmp((*cmd)->path, "exit", 5))
		return (exit_func(cmd, this_env(), out));
	else
		return (0);
}
