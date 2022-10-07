/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_token_content.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridrissi <ridrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 16:40:41 by ridrissi          #+#    #+#             */
/*   Updated: 2022/09/09 18:56:39 by ridrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

void	free_token_content(t_token *token)
{
	t_token	*actuel;

	actuel = token;
	while (actuel != 0)
	{
		if (!(actuel->e_tp >= TOKEN_IN && actuel->e_tp <= TOKEN_END))
			free(actuel->content);
		actuel = actuel->next;
	}
}
