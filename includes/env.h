/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:51:53 by mgranate          #+#    #+#             */
/*   Updated: 2022/11/02 23:08:34 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ENV_H
# define ENV_H

char	**create_env(char **envp);
int		handle_env(t_command *cmd);
void	env_arg(t_command *cmd);
void	print_env();

#endif
