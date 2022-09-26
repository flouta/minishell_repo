/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_rdr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridrissi <ridrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 17:26:57 by ridrissi          #+#    #+#             */
/*   Updated: 2022/08/27 17:27:17 by ridrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_rdr	*ft_lstlast_rdr(t_rdr *lst)
{
	t_rdr	*actuel;

	if (lst == 0)
		return (0);
	actuel = lst;
	while (actuel->next)
		actuel = actuel->next;
	return (actuel);
}
