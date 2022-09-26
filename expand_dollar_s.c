/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_dollar_s.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridrissi <ridrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 16:59:46 by ridrissi          #+#    #+#             */
/*   Updated: 2022/09/09 19:04:34 by ridrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	expand_dollar_s(t_lexer **line, char **str)
{
	void	*p;
	char	*s;
	char	*excode;

	s = *str;
	p = *line;
	*line = init_lexer((*line)->content, (*line)->i + 1);
	free(p);
	p = *str;
	excode = ft_itoa(g_var.exit_code);
	*str = ft_strjoin(s, excode);
	free(p);
	free(excode);
}
