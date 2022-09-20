/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 15:47:11 by mtavares          #+#    #+#             */
/*   Updated: 2022/09/17 15:56:53 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "allocs.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

char	*ft_get_line(char *buff, char *line);
char	*get_next_line(int fd);
int		ft_checknl(char *buff);

#endif
