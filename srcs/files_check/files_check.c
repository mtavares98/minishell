/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 16:37:38 by mtavares          #+#    #+#             */
/*   Updated: 2022/11/23 14:58:17 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* This directory will be reponse of checking if a given file exist */

#include "../../includes/minishell.h"

/*
	It will return a complete path for a file
*/
char	*get_complete_path(char *cmd, char **path)
{
	int		i;
	int		j;
	int		path_size;
	char	*np;

	path_size = string().len(*path, ':');
	np = alloc().calloc(string().len(cmd, -1) + path_size + 1);
	if (!np)
		return (NULL);
	i = -1 * (path != NULL);
	while (path && *path && ++i < path_size - 1)
		np[i] = *(*path)++;
	if (**path == ':' || **path != '\0')
	{
		np[i++] = '/';
		*path += 1;
	}
	j = 0;
	while (cmd && cmd[j])
		np[i++] = cmd[j++];
	return (np);
}

/* This will return an int to see if the command exists */

int	get_full_path(t_command **cmd, char *path)
{
	if (!*cmd)
		return (1);
	if (!path)
		return (print_error_cmd((*cmd), 127, 0));
	while (path)
	{
		if ((*cmd)->path)
			alloc().free_array((*cmd)->path);
		(*cmd)->path = get_complete_path((*cmd)->args[0], &path);
		if (!(*cmd)->path)
		{
			perror("Error malloc");
			return (2);
		}
		if (access((*cmd)->path, F_OK) != -1)
			break ;
		if (!*path)
			return (print_error_cmd((*cmd), 127, 1));
	}
	return (0);
}

/* This function check if a command is builtin */

int	is_builtin(char *cmd)
{
	return (!string().strncmp(cmd, "echo", 5) || \
	!string().strncmp(cmd, "cd", 3) || \
	!string().strncmp(cmd, "pwd", 4) || !string().strncmp(cmd, "export", 7) \
	|| !string().strncmp(cmd, "unset", 6) || !string().strncmp(cmd, "env", 4) \
	|| !string().strncmp(cmd, "exit", 5));
}

/* This will return an int based on (*cmd)->path variable for check
addindex the file exists. If the variable have absolute path it will test
if that file exists based on the path provided. If it isn't an
absolute path it will be search for a Path based on $PATH. */

int	check_files(t_command **cmd, char *path)
{
	t_command	*tmp;
	int			status;

	tmp = *cmd;
	while (tmp)
	{
		if (string().strchr(tmp->path, '/'))
		{
			if (access((*cmd)->path, F_OK) == -1)
			{
				this_env()->status = print_error_cmd(tmp, 127, 1);
				return (1);
			}
		}
		else if (!is_builtin(tmp->path))
		{
			status = get_full_path(&tmp, path);
			this_env()->status = status;
			if (status)
				return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}
