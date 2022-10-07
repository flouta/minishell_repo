/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridrissi <ridrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 17:12:56 by ridrissi          #+#    #+#             */
/*   Updated: 2022/09/09 18:51:59 by ridrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

void	to_add(t_lexer **line, t_token **token, int id, char *value)
{
	void	*p;

	ft_lstadd_backtoken(token, ft_lstnewtoken(id, value));
	p = *line;
	*line = init_lexer((*line)->content, (*line)->i + 1);
	free(p);
}
