/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridrissi <ridrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 17:05:41 by ridrissi          #+#    #+#             */
/*   Updated: 2022/08/27 17:06:20 by ridrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

char	*ft_init(t_lexer **line, int *expd, int *keep_up)
{
	char	*str;
	void	*p;

	g_var.b = 1;
	*expd = 0;
	*keep_up = 1;
	g_var.allow_expand = 1;
	str = (char *) malloc(1 * sizeof(char));
	str[0] = '\0';
	if ((*line)->c == 34 || (*line)->c == 39)
	{
		p = *line;
		*line = init_lexer((*line)->content, (*line)->i + 1);
		free(p);
	}
	return (str);
}
