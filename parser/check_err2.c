/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_err2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridrissi <ridrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 17:48:26 by ridrissi          #+#    #+#             */
/*   Updated: 2022/09/09 19:11:11 by ridrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

int	check_err2(t_token *token)
{
	if (check_double_pipe(token) == 0 || check_pipe_end(token) == 0
		|| check_pipe_start(token) == 0 || check_rdr_end(token) == 0
		|| check_rdr_next(token) == 0)
	{
		free_token_content(token);
		return (0);
	}
	return (1);
}
