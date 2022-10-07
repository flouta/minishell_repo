/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fctn6.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridrissi <ridrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 17:00:25 by ridrissi          #+#    #+#             */
/*   Updated: 2022/08/27 17:00:45 by ridrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

int	ft_fctn6(t_lexer **line, char **str, int quote, t_token **token)
{
	void	*p;

	p = *line;
	*line = init_lexer((*line)->content, (*line)->i + 1);
	free(p);
	if ((*line)->content[(*line)->i] == '?')
		expand_dollar_s(line, str);
	else if (!((*line)->content[(*line)->i] >= '0'
			&& (*line)->content[(*line)->i] <= '9'))
	{
		if (expand_join(str, line, quote, token) == 0)
			return (0);
	}
	else if (((*line)->content[(*line)->i] >= '0'
			&& (*line)->content[(*line)->i] <= '9'))
	{
		p = *line;
		*line = init_lexer((*line)->content, (*line)->i + 1);
		free(p);
	}
	return (1);
}
