/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 23:25:14 by mgranate          #+#    #+#             */
/*   Updated: 2022/09/24 11:15:07 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	clean_stack(t_tmp *s)
{
	t_tmp	*tmp;

	if (s)
	{
		int i = 0;
		while (s)
		{
			i ++;
			printf("I === %d\n", i);
			tmp = (s)->next;
			alloc().free_array((void *)(s));
			s = NULL;
			s = tmp;
		}
		alloc().free_array((void *)(s));
		s = NULL;
	}
}

t_tmp	*str_handler(char *str, t_tmp *head, t_tmp *arg, char **split)
{
	int		i;

	i = -1;
	split = ft_split(str, ' ');
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
	path = NULL;
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
	char		**split;
	
	i = 0;
	head = NULL;
	args = NULL;
	path = NULL;
	split = NULL;
	int j = 0;
	while (str[j])
	{
		if (str[j] == '/')
		{
			path = handler_path(str);
			i = string().len(path, -1);
			break ;
		}
		j++;
	}
	str = str + i;
	head = str_handler(str, head, args, split);
	alloc().free_matrix((void *)(split));
	printf("head == %s\n", head->args);
	cmdfunc().add(path, head);
	clean_stack(head);
	return (1);
}