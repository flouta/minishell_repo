/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fctn9.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridrissi <ridrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 17:04:45 by ridrissi          #+#    #+#             */
/*   Updated: 2022/09/08 14:28:50 by ridrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_fctn9(t_lexer **line, int quote, t_token **token, char **str)
{
	int	expd;

	expd = 0;
	if (quote != 39 && (*line)->c == '$'
		&& (((*line)->content[(*line)->i + 1] >= 'a'
				&& (*line)->content[(*line)->i + 1] <= 'z')
			|| ((*line)->content[(*line)->i + 1] >= 'A'
				&& (*line)->content[(*line)->i + 1] <= 'Z')
			|| ((*line)->content[(*line)->i + 1] >= '0'
				&& (*line)->content[(*line)->i + 1] <= '9')
			|| (*line)->content[(*line)->i + 1] == '?'))
	{
		ft_fctn5(token);
		if (g_var.allow_expand == 1)
		{
			expd = 1;
			if (ft_fctn6(line, str, quote, token) == 0)
				return (-4);
		}
	}
	if (*token && quote == 0 && ft_lstlastoken(*token)->expand_flag == 0
		&& ft_lstlastoken(*token)->e_tp == TOKEN_HEREDOC && g_var.checked == 0)
		ft_lstlastoken(*token)->expand_flag = 1;
	expn_hdoc(token, quote);
	return (expd);
}
