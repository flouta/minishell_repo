/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_token2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridrissi <ridrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 17:13:48 by ridrissi          #+#    #+#             */
/*   Updated: 2022/09/09 19:01:07 by ridrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	add_token2(t_lexer **line, t_token **token, int *quote, int *valid)
{
	void	*p;

	if ((*line)->c == '<' && (*line)->content[(*line)->i + 1] != '<')
		to_add(line, token, TOKEN_IN, "<");
	else if ((*line)->c == '>' && (*line)->content[(*line)->i + 1] != '>')
		to_add(line, token, TOKEN_OUT, ">");
	else if ((*line)->c == '|')
		to_add(line, token, TOKEN_PIPE, "|");
	else if ((*line)->c == ' ')
	{
		p = *line;
		*line = init_lexer((*line)->content, (*line)->i + 1);
		free(p);
	}
	else
	{
		*quote = 0;
		*valid = 0;
		g_var.checked = 0;
		if (add_str(line, *quote, token, valid) == 0)
			return (0);
	}
	return (1);
}
