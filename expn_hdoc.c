/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expn_hdoc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridrissi <ridrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 17:03:57 by ridrissi          #+#    #+#             */
/*   Updated: 2022/09/09 18:59:03 by ridrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	expn_hdoc(t_token **token, int quote)
{
	if (*token && quote != 0
		&& ft_lstlastoken(*token)->e_tp == TOKEN_HEREDOC)
	{
		ft_lstlastoken(*token)->expand_flag = 0;
		g_var.checked += 1;
	}
}
