/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fctn4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridrissi <ridrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 16:57:39 by ridrissi          #+#    #+#             */
/*   Updated: 2022/09/09 18:05:08 by ridrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	lexer_advance(t_lexer **line)
{
	void	*p;

	p = *line;
	*line = init_lexer((*line)->content, (*line)->i + 3);
	free(p);
}

void	ft_fctn4(t_lexer **line, int *quote, int *valid)
{
	void	*p;

	if (*quote == 0 && ((*line)->content[(*line)->i + 1] == 34
			|| (*line)->content[(*line)->i + 1] == 39) && (*line)->c == '$')
	{
		if ((*line)->content[(*line)->i + 1]
			== (*line)->content[(*line)->i + 2])
			lexer_advance(line);
		else
		{
			p = *line;
			*line = init_lexer((*line)->content, (*line)->i + 1);
			free(p);
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
}
