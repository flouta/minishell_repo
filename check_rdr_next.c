/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rdr_next.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridrissi <ridrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 17:47:46 by ridrissi          #+#    #+#             */
/*   Updated: 2022/09/09 18:59:53 by ridrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_rdr_next(t_token *token)
{
	t_token	*actuel;

	actuel = token;
	while (actuel->e_tp != TOKEN_END)
	{
		if ((actuel->e_tp == TOKEN_IN || actuel->e_tp == TOKEN_OUT
				|| actuel->e_tp == TOKEN_APPEND
				|| actuel->e_tp == TOKEN_HEREDOC) && actuel->next
			&& (actuel->next->e_tp != TOKEN_STR))
			return (print_error());
		actuel = actuel->next;
	}
	return (1);
}
