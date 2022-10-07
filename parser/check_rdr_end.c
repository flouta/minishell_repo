/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rdr_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridrissi <ridrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 17:46:43 by ridrissi          #+#    #+#             */
/*   Updated: 2022/09/09 18:59:56 by ridrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

int	check_rdr_end(t_token *token)
{
	t_token	*actuel;

	actuel = token;
	while (actuel->e_tp != TOKEN_END)
		actuel = actuel->next;
	if (actuel->prev && (actuel->prev->e_tp == TOKEN_IN
			|| actuel->prev->e_tp == TOKEN_OUT
			|| actuel->prev->e_tp == TOKEN_APPEND
			|| actuel->prev->e_tp == TOKEN_HEREDOC))
		return (print_error());
	return (1);
}
