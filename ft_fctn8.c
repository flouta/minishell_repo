/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fctn8.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridrissi <ridrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 17:02:39 by ridrissi          #+#    #+#             */
/*   Updated: 2022/08/27 17:03:20 by ridrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_fctn8(t_lexer **line, int *valid, int *quote)
{
	void	*p;

	if ((*line)->c == 34 || (*line)->c == 39)
	{	
		*valid += 1;
		if ((*line)->c == 34)
			*quote = 34;
		else
			*quote = 39;
		p = *line;
		*line = init_lexer((*line)->content, (*line)->i + 1);
		free(p);
	}
}
