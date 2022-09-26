/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridrissi <ridrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 17:39:55 by ridrissi          #+#    #+#             */
/*   Updated: 2022/09/09 19:00:02 by ridrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_quote(char *str, int quote, int *index)
{
	int	closed;

	closed = 0;
	while (str[*index] != '\0' && !closed)
	{
		if (str[*index] == quote)
			closed++;
		(*index)++;
	}
	if (closed == 0)
	{
		free(str);
		return (print_error());
	}
	return (1);
}
