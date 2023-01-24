/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_fd.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 14:46:10 by mtavares          #+#    #+#             */
/*   Updated: 2022/06/08 15:50:57 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_FD_H
# define PRINTF_FD_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef unsigned long		t_lu;
typedef unsigned int		t_ui;
typedef struct s_info		t_info;
# define HEXUP 				"0123456789ABCDEF"
# define HEXLO 				"0123456789abcdef"
# define DEC				"0123456789"
# define STR				0
# define CHAR				1

struct s_info
{
	int			fd;
	int			base;
	size_t		i;
	size_t		counter;
};

int		printf_fd(int fd, const char *str, ...);

#endif