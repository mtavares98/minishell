/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 23:25:14 by mgranate          #+#    #+#             */
/*   Updated: 2022/09/23 16:32:22 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_tmp	*str_handler(char *str, t_tmp *head, t_tmp *arg)
{
	char	**split;
	int		i;
	int		sz;
	
	i = -1;
	sz = 0;
	split = ft_split(str, ' ');
	while (split[sz])
		sz++;
	while (split[++i])
	{
		arg = create_single_node(split[i]);
		arg->next = head;
		head = arg;		
	}
	return (head);
}

char	*handler_path(char *str)
{
	int		i;
	char	*path;
	
	i = 0;
	while (*str && *str == ' ')
		str++;
	if (*str != '/')
		return (0);
	while (str[i] && (string().ft_isalnum(str[i]) || str[i] == '/'))
		i++;
	path = string().substr(str, 0, i);
	str = str + i;
	return (path);
}

int	argm_handler(char *str)
{
	static	t_tmp	*head;
	static	t_tmp	*args;
	char			*path;
	int				i;
	
	path = handler_path(str);
	i = string().len(path, -1);
	str = str + i;
	printf("str == %s", str);
	head = str_handler(str, head, args);
	cmdfunc().add(path, head);
	free (path);
	
	return (1);
}