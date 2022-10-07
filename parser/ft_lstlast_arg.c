/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_arg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridrissi <ridrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 17:28:28 by ridrissi          #+#    #+#             */
/*   Updated: 2022/08/27 17:28:37 by ridrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

t_args	*ft_lstlast_arg(t_args *lst)
{
	t_args	*actuel;

	if (lst == 0)
		return (0);
	actuel = lst;
	while (actuel->next)
		actuel = actuel->next;
	return (actuel);
}
