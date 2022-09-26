/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fctn1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridrissi <ridrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 16:54:45 by ridrissi          #+#    #+#             */
/*   Updated: 2022/08/27 16:55:17 by ridrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_fctn1(t_lexer **line, int *valid, int *keep_up)
{
	if (((*line)->c == '\0' || (*line)->c == ' ' || (*line)->c == '<'
			|| (*line)->c == '>' || (*line)->c == '|') && (*valid))
		*keep_up = 1;
	else if (((*line)->c == '\0' || (*line)->c == ' ' || (*line)->c == '<'
			|| (*line)->c == '>' || (*line)->c == '|') && !(*valid))
		*keep_up = 0;
}
