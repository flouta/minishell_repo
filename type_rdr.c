/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_rdr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridrissi <ridrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 17:36:50 by ridrissi          #+#    #+#             */
/*   Updated: 2022/09/09 18:51:47 by ridrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	type_rdr(t_token *actuel_tk, t_cmd **actuel)
{
	int	ret;

	ret = 1;
	if (actuel_tk->ambg == 1)
		g_var.ambgs = -1;
	else if (actuel_tk->ambg != 1)
		g_var.ambgs = 0;
	if (actuel_tk->e_tp == TOKEN_IN && actuel_tk->next->e_tp == TOKEN_STR)
		ardr(&((*actuel)->rdr), actuel_tk->next->content,
			IN, actuel_tk->expand_flag);
	else if (actuel_tk ->e_tp == TOKEN_OUT
		&& actuel_tk->next->e_tp == TOKEN_STR)
		ardr(&((*actuel)->rdr), actuel_tk->next->content,
			OUT, actuel_tk->expand_flag);
	else if (actuel_tk ->e_tp == TOKEN_APPEND
		&& actuel_tk->next->e_tp == TOKEN_STR)
		ardr(&((*actuel)->rdr), actuel_tk->next->content,
			OUT_APPEND, actuel_tk->expand_flag);
	else if (actuel_tk ->e_tp == TOKEN_HEREDOC
		&& actuel_tk->next->e_tp == TOKEN_STR)
		ardr(&((*actuel)->rdr), actuel_tk->next->content,
			IN_HEREDOC, actuel_tk->expand_flag);
	else
		ret = 0;
	return (ret);
}
