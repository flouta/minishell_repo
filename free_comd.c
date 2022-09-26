/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_comd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridrissi <ridrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 18:33:34 by ridrissi          #+#    #+#             */
/*   Updated: 2022/09/09 18:57:28 by ridrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_comd(t_cmd *comd)
{
	t_cmd	*actuel;
	t_cmd	*tmp;

	actuel = comd;
	while (actuel != 0)
	{
		free_cmdcnt(actuel);
		tmp = actuel;
		actuel = actuel->next;
		free(tmp);
	}
}
