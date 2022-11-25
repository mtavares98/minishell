/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 15:41:29 by mtavares          #+#    #+#             */
/*   Updated: 2022/11/25 18:11:06 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RED_H
# define RED_H

typedef struct s_red		t_red;
typedef struct s_redfunc	t_redfunc;

struct s_redfunc
{
	t_red	*(*add)(char *file, int is_double, int is_output);
	t_red	*(*get)(int i);
	void	(*remove)(int i);
};

struct s_red
{
	int		fd;
	int		is_double;
	int		is_output;
	char	*file;
	t_red	*next;
};

t_red		**this_red(void);
t_redfunc	redfunc(void);

#endif
