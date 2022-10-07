/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fctn2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridrissi <ridrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 16:56:11 by ridrissi          #+#    #+#             */
/*   Updated: 2022/09/09 18:56:24 by ridrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

void	ft_fctn2(t_lexer **line, char **str, int *valid, int *quote)
{
	char	*join;
	void	*p;

	p = char_to_str((*line)->c);
	join = ft_strjoin(*str, (char *)p);
	free(p);
	free(*str);
	*str = join;
	p = *line;
	*line = init_lexer((*line)->content, (*line)->i + 1);
	free(p);
	if (*quote == 0 && ((*line)->c == 34 || (*line)->c == 39))
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
