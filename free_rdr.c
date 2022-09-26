/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_rdr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridrissi <ridrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 18:27:45 by ridrissi          #+#    #+#             */
/*   Updated: 2022/09/09 18:57:07 by ridrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_rdr(t_rdr *rdr)
{
	t_rdr	*actuel;
	t_rdr	*tmp;

	actuel = rdr;
	while (actuel != 0)
	{
		if (actuel->content[0] != '\0')
			free(actuel->content);
		tmp = actuel;
		actuel = actuel->next;
		free(tmp);
	}
}
