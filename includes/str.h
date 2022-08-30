/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   library.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 15:26:51 by mtavares          #+#    #+#             */
/*   Updated: 2022/08/30 18:25:13 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBRARY_H
# define LIBRARY_H

# include <stdlib.h>

typedef struct s_str	t_str;

struct s_str
{
	int		(*len)(char *s);
	char	*(*strchr)(char *s, char c);
	char	*(*strrchr)(char *s, char c);
	char	*(*trim)(char *s1, char *set);
};

char	*strtrim(char *s1, char *set);
char	*ft_strrchr(char *str, char c);
char	*ft_strchr(char *str, char c);
int		ft_strlen(char *str);
t_str	str(void);

#endif
