/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate_ls <mgranate_ls@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 19:43:44 by mgranate          #+#    #+#             */
/*   Updated: 2023/01/25 01:40:21 by mgranate_ls      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*handle_path(char *split)
{
	int		sz;
	char	*tmp;
	int		i;

	i = 0;
	sz = string().len(split, - 1);
	while (split[--sz] != '/')
		i++;
	tmp = string().substr(split, sz + 1, i);
	while (split[++i])
		split[i] = '\0';
	alloc().free_array(split);
	return (tmp);
}

int	add_command(char **split, t_command *cmd, int i)
{
	int	j;

	cmd->args = alloc().calloc((list_size(split, "<|>") + 1) * sizeof(char **));
	j = 0;
	cmd->path = string().strdup(split[i]);
	if (split[0][0] == '/')
		split[i] = handle_path(split[i]);
	while (split[i] && split[i][0] != '|' && split[i][0] != '<' && split[i][0] != '>')
	{
		cmd->args[j++] = string().strdup(split[i++]);
		printf("cmd: %s\n", cmd->args[i]);
	}
	return(i);
}

int	get_redirections(char *split, int i)
{
	 char *file;

	 file = string().strdup(split);
	 printf("file: %s\n", file);
	 if (!file)
		  return 1;
	if (i == 1)
		redfunc().add(file, 0, 1, this_red(NULL));
	if (i == 2)
		redfunc().add(file, 1, 1, this_red(NULL));
	if (i == 3)
		redfunc().add(file, 0, 0, this_red(NULL));
	if (i == 4)
		redfunc().add(file, 1, 0, this_red(NULL));
	return (1);
}

int	check_redirection(char **split, t_command *cmd, int i)
{
	 if(split[i][0] != '>' || split[i][0] != '<')
	 	return(0);
	 this_red(cmd->io);
	 if (split[i][1] && split[i][0] == '>' && split[i][1] == '>')
		  get_redirections(split[i + 1], 2);
	 else if (split[i][1] && split[i][0] == '<' && split[i][1] == '<')
		  get_redirections(split[i + 1], 4);
	 else if (split[i][0] == '>')
		  get_redirections(split[i + 1], 1);
	 else if (split[i][0] == '<')
		  get_redirections(split[i + 1], 3);
	return (1);
}