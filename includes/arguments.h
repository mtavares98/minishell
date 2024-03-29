/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:09:39 by mgranate          #+#    #+#             */
/*   Updated: 2023/01/26 16:48:37 by mtavares         ###   ########.fr       */
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
int		check_reds(char *s);
int		check_redirection(char **split, t_command *cmd, int i);
int		add_command(char *split, t_command *cmd);

void	splitcpy(char *dst, char *src, int sz);

char	**ft_split(char *s);
char	**recicly_split(char **split);
char	*get_substring(char *str, char c);
char	*path_handler2(char *str, char *path);
char	*handler_path(char *str);
char	*remove_quotes(char *argm);

#endif
