/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 12:14:24 by mgranate          #+#    #+#             */
/*   Updated: 2022/11/23 00:46:27 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANDER_H
# define EXPANDER_H

# include <unistd.h>
# include <stdio.h>
# include "execution.h"

int		check_alloc_size(char *str, char *env, int ctr);
int		ft_strcpy(char *tmp, char *str, char c);
int		check_single_quote(char *split, int i, char c);
char	*pid_switch(char *str);
char	*get_status(char *str);

#endif
