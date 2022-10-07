/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridrissi <ridrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 17:37:58 by ridrissi          #+#    #+#             */
/*   Updated: 2022/09/09 18:54:23 by ridrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

void	parser(t_token *token, t_cmd **comd)
{
	t_cmd	**actuel;
	t_token	*actuel_tk;

	actuel = comd;
	actuel_tk = token;
	while (actuel_tk->e_tp != TOKEN_END)
	{
		if (type_rdr(actuel_tk, actuel))
			actuel_tk = actuel_tk->next;
		else if (actuel_tk->e_tp == TOKEN_STR)
		{
			if ((*actuel)->cmd == 0)
				(*actuel)->cmd = actuel_tk ->content;
			else if ((*actuel)->cmd != 0)
				ft_lstadd_back_arg(&((*actuel)->args),
					ft_lstnew_arg(actuel_tk ->content));
		}
		else if (actuel_tk->e_tp == TOKEN_PIPE)
		{
			ft_lstadd_back_cmd(comd, ft_lstnew_cmd());
			actuel = &((*actuel)->next);
		}
		actuel_tk = actuel_tk->next;
	}
}
