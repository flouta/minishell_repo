/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridrissi <ridrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 17:16:42 by ridrissi          #+#    #+#             */
/*   Updated: 2022/09/09 18:52:54 by ridrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

void	step1(t_lexer **line, int *quote, int *valid)
{
	if ((*line)->c == 34)
		*quote = 34;
	else
		*quote = 39;
	*valid = 1;
}
