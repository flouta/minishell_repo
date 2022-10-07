/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridrissi <ridrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 18:30:13 by ridrissi          #+#    #+#             */
/*   Updated: 2022/09/09 18:57:44 by ridrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

void	free_args(t_args *args)
{
	t_args	*actuel;
	t_args	*tmp;

	actuel = args;
	while (actuel != 0)
	{
		if (actuel->arg[0] != '\0')
			free(actuel->arg);
		tmp = actuel;
		actuel = actuel->next;
		free(tmp);
	}
}
