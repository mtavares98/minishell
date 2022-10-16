/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:09:39 by mgranate          #+#    #+#             */
/*   Updated: 2022/10/01 17:53:30 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  ARGUMENTS_H
# define ARGUMENTS_H

# include "execution.h"

int	        receive_args(char *str);
int	        argm_handler(char *str);
void	    printlist(t_command *vars);
t_tmp	    *create_single_node(char *value);
char	    **ft_split(char *s, char c);
char		**recicly_split(char **split);
char		*get_substring(char *str, char c);

#endif