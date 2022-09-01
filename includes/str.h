/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 15:26:51 by mtavares          #+#    #+#             */
/*   Updated: 2022/08/31 17:28:58 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STR_H
# define STR_H

# include <stdlib.h>

typedef struct s_str	t_str;

struct s_str
{
	int		(*len)(char *s);
	char	*(*strchr)(char *s, char c);
	char	*(*strrchr)(char *s, char c);
	char	*(*trim)(char *s1, char *set);
	char	**(*split)(char *s, char *c);
};

char	**split(char *s, char *c);
char	*strtrim(char *s1, char *set);
char	*ft_strrchr(char *str, char c);
char	*ft_strchr(char *str, char c);
int		ft_strlen(char *str);
t_str	__str__(void);

#endif
