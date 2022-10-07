/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_lexer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridrissi <ridrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 16:26:49 by ridrissi          #+#    #+#             */
/*   Updated: 2022/09/09 18:55:41 by ridrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

t_lexer	*init_lexer(char *value, int i)
{
	t_lexer	*lx;

	lx = (t_lexer *) malloc(sizeof(t_lexer));
	if (!lx)
		return (0);
	lx->i = i;
	lx->content = value;
	lx->c = lx->content[lx->i];
	return (lx);
}
