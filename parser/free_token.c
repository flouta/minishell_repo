/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridrissi <ridrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 18:34:58 by ridrissi          #+#    #+#             */
/*   Updated: 2022/09/09 18:56:49 by ridrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

void	free_token(t_token *token)
{
	t_token	*actuel;
	t_token	*tmp;

	actuel = token;
	while (actuel != 0)
	{
		tmp = actuel;
		actuel = actuel->next;
		free(tmp);
	}
}
