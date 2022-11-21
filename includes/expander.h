/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 12:14:24 by mgranate          #+#    #+#             */
/*   Updated: 2022/11/19 02:35:51 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANDER_H
# define EXPANDER_H

# include <unistd.h>
# include <stdio.h>
# include "execution.h"

int		check_alloc_size(char *str, char *env);
int		ft_strcpy(char *str, char *str2, char c);
int		check_single_quote(char *split, int i);


#endif
