/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:09:39 by mgranate          #+#    #+#             */
/*   Updated: 2022/11/29 19:47:19 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  ARGUMENTS_H
# define ARGUMENTS_H

# include "execution.h"
# include "expander.h"

int		receive_args(char *str);
int		argm_handler(char *str);
int		validate_string(char *str);
int		check_spaces(char *s);
int		check_redirection(char **split);

// void	printlist(t_command *vars);
//Functions that will handle the arguments receive
//and separate them into path and argms:
char	**ft_split(char *s, char c);
char	**recicly_split(char **split);
char	*get_substring(char *str, char c);
char	*handle_split(char *split);
char	*path_handler2(char * str, char *path);
char	*handler_path(char *str);
char	*remove_quotes(char *argm);

#endif
