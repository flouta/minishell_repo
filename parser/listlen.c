/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listlen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridrissi <ridrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 17:50:01 by ridrissi          #+#    #+#             */
/*   Updated: 2022/09/09 18:55:23 by ridrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

int	listlen(t_args *args)
{
	int		len;
	t_args	*actuel;

	len = 0;
	actuel = args;
	while (actuel != 0)
	{
		len++;
		actuel = actuel->next;
	}
	return (len);
}
