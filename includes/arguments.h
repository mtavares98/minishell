/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:09:39 by mgranate          #+#    #+#             */
/*   Updated: 2022/10/26 14:35:13 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  ARGUMENTS_H
# define ARGUMENTS_H

# include "execution.h"

int		receive_args(char *str);
int		argm_handler(char *str);
int		validate_string(char *str);

void	printlist(t_command *vars);
t_tmp	*create_single_node(char *value);
//Functions that will handle the arguments receive
//and separate them into path and argms:
char	**ft_split(char *s, char c);
char	**recicly_split(char **split);
char	*get_substring(char *str, char c);
char	*handle_split(char *split);
char	*path_handler2(char * str, char *path);
char	*handler_path(char *str);

#endif
