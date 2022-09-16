/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 15:26:51 by mtavares          #+#    #+#             */
/*   Updated: 2022/09/16 23:32:29 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STR_H
# define STR_H

# include <stdlib.h>
# include <limits.h>

typedef struct s_str	t_str;

struct s_str
{
	int		(*len)(char *s);
	int		(*strncmp)(char *s1, char *s2, size_t n);
	long	(*atoi)(char *s);
	char	*(*strchr)(char *s, char c);
	char	*(*strrchr)(char *s, char c);
	char	*(*trim)(char *s1, char *set);
	int		(*isdig)(char c);
	int		(*isspace)(char c);
	char	*(*itoa)(char *s, int *maxdig, int counter, int n);
};

t_str	string(void);

#endif
