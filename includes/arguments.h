/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:09:39 by mgranate          #+#    #+#             */
/*   Updated: 2023/01/23 17:17:51 by mtavares         ###   ########.fr       */
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
int		skip_quotes(char *s, char c);
int 	check_reds(char *s);
int	    check_redirection(char **split, t_command *cmd);

void	splitcpy(char *dst, char *src, int sz);
// void	printlist(t_command *vars);
//Functions that will handle the arguments receive
//and separate them into path and argms:
char	**ft_split(char *s);
char	**recicly_split(char **split);
char	*get_substring(char *str, char c);
char	*handle_split(char *split);
char	*path_handler2(char * str, char *path);
char	*handler_path(char *str);
char	*remove_quotes(char *argm);

#endif
