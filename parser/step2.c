/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridrissi <ridrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 17:14:52 by ridrissi          #+#    #+#             */
/*   Updated: 2022/09/09 18:52:44 by ridrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

void	step2(t_lexer **line, t_token **token, int *r)
{
	void	*p;

	*r += 1;
	ft_lstadd_backtoken(token, ft_lstnewtoken(TOKEN_APPEND, ">>"));
	p = *line;
	*line = init_lexer((*line)->content, (*line)->i + 1);
	free(p);
	p = *line;
	*line = init_lexer((*line)->content, (*line)->i + 1);
	free(p);
}
