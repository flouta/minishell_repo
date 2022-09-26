/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridrissi <ridrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 17:19:46 by ridrissi          #+#    #+#             */
/*   Updated: 2022/09/09 17:47:24 by ridrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	add_token(t_lexer **line, t_token **token)
{
	int	valid;
	int	quote;
	int	rt;

	quote = 0;
	valid = 0;
	rt = 0;
	while ((*line)->c != '\0')
	{
		if (assign(&rt, add_token1(line, token, &quote, &valid)) == 0)
			return (0);
		else if (rt != 1)
		{
			if (add_token2(line, token, &quote, &valid) == 0)
				return (0);
		}
	}
	ft_lstadd_backtoken(token, ft_lstnewtoken(TOKEN_END, "\0"));
	return (1);
}
