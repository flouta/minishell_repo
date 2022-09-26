/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntaxerr_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridrissi <ridrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 17:40:44 by ridrissi          #+#    #+#             */
/*   Updated: 2022/09/09 18:52:34 by ridrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	syntaxerr_checker(char *str)
{
	int	quote;
	int	i;
	int	index;

	quote = 0;
	i = 0;
	index = 0;
	while (str[index] != '\0')
	{
		while (str[i] != 34 && str[i] != 39 && str[i] != '\0')
			i++;
		index = i;
		if (str[i] == 34 || str[i] == 39)
		{
			if (str[i] == 34)
				quote = 34;
			else if (str[i] == 39)
				quote = 39;
			index += 1;
			if (check_quote(str, quote, &index) == 0)
				return (0);
			i = index;
		}
	}
	return (1);
}
