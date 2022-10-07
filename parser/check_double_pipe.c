/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_double_pipe.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridrissi <ridrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 17:42:06 by ridrissi          #+#    #+#             */
/*   Updated: 2022/09/09 19:00:16 by ridrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

int	check_double_pipe(t_token *token)
{
	t_token	*actuel;

	actuel = token;
	while (actuel->e_tp != TOKEN_END)
	{
		if (actuel->e_tp == TOKEN_PIPE && actuel->next->e_tp == TOKEN_PIPE)
			return (print_error());
		actuel = actuel->next;
	}
	return (1);
}
