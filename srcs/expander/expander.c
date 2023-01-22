/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 17:28:52 by mgranate          #+#    #+#             */
/*   Updated: 2023/01/17 19:06:40 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/expander.h"
#include "../../includes/arguments.h"

char	*replace_argm(char *str, char *env)
{
	char	*tmp;
	int		i;

	tmp = str;
	i = check_alloc_size(str, env, 1);
	str = alloc().calloc(i + 1);
	if (!str)
	{
		str = tmp;
		return (str);
	}
	i = ft_strcpy(tmp, str, '$');
	ft_strcpy(env + string().len(env, '='), str + string().len(str, -1), -1);
	i = i + string().len(env, '=');
	ft_strcpy(tmp + i, str + string().len(str, -1), -1);
	alloc().free_array(tmp);
	return (str);
}

char	*remove_exp(char *str)
{
	char	*tmp;
	int		i;

	tmp = str;
	i = 0;
	i = check_alloc_size(str, NULL, -1);
	str = alloc().calloc(i + 1);
	if (!str)
	{
		str = tmp;
		return (str);
	}
	i = ft_strcpy(tmp, str, '$');
	while (tmp[++i] && string().ft_isalnum(tmp[i]))
		;
	if (tmp[i])
		ft_strcpy(tmp + i, str + string().len(str, -1), -1);
	alloc().free_array(tmp);
	return (str);
}

char	*search_for_env(char *str, char *tmp, t_env *env)
{
	int	i;
	int	ck;

	ck = 0;
	i = -1;
	while (env->env[++i])
	{
		if ((!string().strncmp(tmp, env->env[i], string().len(env->env[i], '=') - 1)
			&& (string().len(tmp, -1) == string().len(env->env[i], '=') - 1)))
		{
			str = replace_argm(str, env->env[i]);
			ck++;
		}
	}
	if (ck == 0)
		str = remove_exp(str);
	return (str);
}

char	*check_dollar(char *str, int j, t_env *env)
{
	int		i;
	char	*tmp;

	i = j + 1;
	if (str[i] == '$')
		str = pid_switch(str);
	else if (str[i] == '?')
		str = get_status(str);
	else if (!string().ft_isalnum(str[i]))
		str = remove_exp(str);
	else
	{
		while (str[i] && string().ft_isalnum(str[i]))
			i++;
		tmp = string().substr(str, j + 1, i - j - 1);
		if (!tmp)
			return (str);
		str = search_for_env(str, tmp, env);
		alloc().free_array(tmp);
	}
	return (str);
}

int	check_expander(char **split, t_env *env)
{
	int		i;
	int		j;
	int		ctr;

	ctr = 1;
	i = -1;
	while (split[++i])
	{
		j = -1;
		if (split[i] != split[0])
			if (split[i - 1][0] == '<' && split[i - 1][1] == '<')
				ctr = 0;
		while (split[i][++j] && ctr == 1)
		{
			if (split[i][j] == '\'')
				j = check_single_quote(split[i], j, '\'');
			if (split[i][j] == '$' && split[i][j + 1])
			{
				split[i] = check_dollar(split[i], j, env);
				//if (check_dollar_sign(split[i]))
				j = -1;
			}
		}
		split[i] = remove_quotes(split[i]);
		ctr = 1;
	}
	return (1);
}
