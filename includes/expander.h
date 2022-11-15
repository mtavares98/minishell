/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 12:14:24 by mgranate          #+#    #+#             */
/*   Updated: 2022/11/15 12:15:39 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANDER_H
# define EXPANDER_H

# include "env.h"
# include <unistd.h>
# include <stdio.h>

typedef struct s_set		t_set;

struct s_set
{
	char	**set;
	int		count;
};

#endif
