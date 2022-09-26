/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_token1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridrissi <ridrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 17:18:51 by ridrissi          #+#    #+#             */
/*   Updated: 2022/09/09 23:07:04 by ridrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	addit_empty(t_lexer **line, t_token **token, int *r)
{
	void	*p;

	*r += 1;
	ft_lstadd_backtoken(token, ft_lstnewtoken(TOKEN_STR, ""));
	p = *line;
	*line = init_lexer((*line)->content, (*line)->i + 3);
	free(p);
}

static int	nextc(char c1, char c2, char c3)
{
	if ((c1 == 34 || c1 == 39) && (c2 == c1) && (c3 == ' '
			|| c3 == '<' || c3 == '>' || c3 == '|' || c3 == '\0'))
		return (1);
	return (0);
}

static int	existt(t_lexer **line)
{
	if ((*line)->content[(*line)->i + 1] && (*line)->content[(*line)->i + 2]
		&& (*line)->content[(*line)->i + 3])
	{
		return (1);
	}
	return (0);
}

int	add_token1(t_lexer **line, t_token **token, int *quote, int *valid)
{
	int		r;
	void	*p;

	r = 2;
	if (((*line)->c == '$') && existt(line)
		&& nextc((*line)->content[(*line)->i + 1],
			(*line)->content[(*line)->i + 2], (*line)->content[(*line)->i + 3]))
		addit_empty(line, token, &r);
	else if (((*line)->c == 34) || ((*line)->c == 39))
	{
		r = 1;
		if (quote_str(line, token, quote, valid) == 0)
			return (0);
	}
	else if ((*line)->c == '>' && (*line)->content[(*line)->i + 1] == '>')
		step2(line, token, &r);
	else if ((*line)->c == '<' && (*line)->content[(*line)->i + 1] == '<')
	{
		r = 1;
		ft_lstadd_backtoken(token, ft_lstnewtoken(TOKEN_HEREDOC, "<<"));
		p = *line;
		*line = init_lexer((*line)->content, (*line)->i + 2);
		free(p);
	}
	return (r);
}
