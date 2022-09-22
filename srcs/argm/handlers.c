/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 23:25:14 by mgranate          #+#    #+#             */
/*   Updated: 2022/09/21 14:08:05 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"


int	argm_handler(char *str)
{
	t_tmp_arg	*head;
	t_tmp_arg	*args;
	int			j;

	j = 0;
	str = str + 4;
	while (str[j])
	{
		args = create_single_node("hello");
		args->next = head;
		head = args;
		j++;
	}
	// Create a loop that finds the first (character || " || ') 
	// There should be two funcitons to handle the substring (one already made for the " && ')
	// The return value of that function should be the substring of what we got from the original string
	// Add that substring to the tmp_arg list
	// Each time it loops and a substring is created, the function that receives the substrings needs to know
	// where to start iterating on the string (maybe sent a counter pointer - already set fot the " ' function)
	// In the end of the loop use crate new node - Arguments already inside.
	// ATTENTION == ECHO FUNCTION DOES NOT RETURNS SPACES, ONLY BETWEEN "" || ''. 
	cmdfunc().add("echo", head);
	printlist(*this());
	// DON'T FORGET TO CLEAN THE tmp_LIST 
	return (1);
}