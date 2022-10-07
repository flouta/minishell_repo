/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlastoken.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridrissi <ridrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 16:27:56 by ridrissi          #+#    #+#             */
/*   Updated: 2022/08/27 19:21:49 by ridrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

t_token	*ft_lstlastoken(t_token *lst)
{
	t_token	*actuel;

	if (lst == 0)
		return (0);
	actuel = lst;
	while (actuel->next)
		actuel = actuel->next;
	return (actuel);
}
