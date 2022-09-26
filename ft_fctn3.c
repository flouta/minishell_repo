/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fctn3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridrissi <ridrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 16:56:59 by ridrissi          #+#    #+#             */
/*   Updated: 2022/09/09 15:12:37 by ridrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_fctn3(t_lexer **line, int *quote, int *valid)
{
	void	*p;

	if (*quote == 0 && ((*line)->c == 34 || (*line)->c == 39))
	{		
		if ((*line)->c == 34)
			*quote = 34;
		else
			*quote = 39;
		*valid += 1;
		p = *line;
		*line = init_lexer((*line)->content, (*line)->i + 1);
		free(p);
	}
}
