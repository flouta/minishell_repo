/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridrissi <ridrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 17:21:58 by ridrissi          #+#    #+#             */
/*   Updated: 2022/08/27 17:22:11 by ridrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

t_cmd	*ft_lstlast_cmd(t_cmd *lst)
{
	t_cmd	*actuel;

	if (lst == 0)
		return (0);
	actuel = lst;
	while (actuel->next)
		actuel = actuel->next;
	return (actuel);
}
