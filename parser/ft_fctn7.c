/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fctn7.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridrissi <ridrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 17:01:50 by ridrissi          #+#    #+#             */
/*   Updated: 2022/08/27 19:18:42 by ridrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

void	ft_fctn7(t_lexer **line)
{
	void	*p;

	if ((*line)->c != '\0' && (*line)->c != ' ' && (*line)->c != '<'
		&& (*line)->c != '>' && (*line)->c != '|' )
	{
		p = *line;
		*line = init_lexer((*line)->content, (*line)->i + 1);
		free(p);
	}
	if ((*line)->c == '\0' || (*line)->c == ' ' || (*line)->c == '<'
		|| (*line)->c == '>' || (*line)->c == '|')
		g_var.b = 0;
}
