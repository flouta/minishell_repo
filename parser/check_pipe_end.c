/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pipe_end.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridrissi <ridrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 17:43:59 by ridrissi          #+#    #+#             */
/*   Updated: 2022/09/09 19:00:07 by ridrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

int	check_pipe_end(t_token *token)
{
	t_token	*actuel;

	actuel = token;
	while (actuel->e_tp != TOKEN_END)
	{
		actuel = actuel->next;
	}
	if (actuel->prev && actuel->prev->e_tp == TOKEN_PIPE)
		return (print_error());
	return (1);
}
