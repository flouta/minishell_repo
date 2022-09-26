/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pipe_start.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridrissi <ridrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 17:45:56 by ridrissi          #+#    #+#             */
/*   Updated: 2022/09/09 19:00:05 by ridrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_pipe_start(t_token *token)
{
	t_token	*actuel;

	actuel = token;
	if (token->e_tp == TOKEN_PIPE)
		return (print_error());
	return (1);
}
