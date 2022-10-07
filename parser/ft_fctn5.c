/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fctn5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridrissi <ridrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 16:58:20 by ridrissi          #+#    #+#             */
/*   Updated: 2022/09/08 14:27:26 by ridrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

void	ft_fctn5(t_token **token)
{
	if (*token && ft_lstlastoken(*token)->e_tp == TOKEN_HEREDOC)
		g_var.allow_expand = 0;
	else if (*token && ft_lstlastoken(*token)->e_tp != TOKEN_HEREDOC)
		g_var.allow_expand = 1;
}
