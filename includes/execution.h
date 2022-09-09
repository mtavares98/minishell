/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 21:48:18 by mtavares          #+#    #+#             */
/*   Updated: 2022/09/08 15:44:21 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

typedef struct s_command		t_command;
typedef struct s_redirection	t_redirection;

struct s_command
{
	int			status;
	char		*path;
	int			abs_path;
	char		**args;
	t_command	*next;
};

struct s_redirection
{
	char	*limiter;
	int		heredoc;
	char	*infile;
	int		infd;
	char	*outfile;
	int		outfd;
};

#endif
