/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridrissi <ridrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 17:17:31 by ridrissi          #+#    #+#             */
/*   Updated: 2022/09/09 18:54:01 by ridrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_nc(char c)
{
	if (c == ' ' || c == '<' || c == '>'
		|| c == '|' || c == '\0')
		return (1);
	return (0);
}

int	quote_str(t_lexer **line, t_token **token, int *quote, int *valid)
{
	void	*p;

	if ((*line)->content[(*line)->i + 1] == (*line)->c
		&& check_nc((*line)->content[(*line)->i + 2]))
	{
		ft_lstadd_backtoken(token, ft_lstnewtoken(TOKEN_STR, ""));
		p = *line;
		*line = init_lexer((*line)->content, (*line)->i + 1);
		free(p);
		p = *line;
		*line = init_lexer((*line)->content, (*line)->i + 1);
		free(p);
	}
	else
	{
		step1(line, quote, valid);
		g_var.checked = 0;
		if (add_str(line, *quote, token, valid) == 0)
			return (0);
	}
	return (1);
}
