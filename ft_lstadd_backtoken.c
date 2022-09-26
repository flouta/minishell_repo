/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_backtoken.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridrissi <ridrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 16:35:26 by ridrissi          #+#    #+#             */
/*   Updated: 2022/08/27 16:35:38 by ridrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_lstadd_backtoken(t_token **lst, t_token *new)
{
	t_token	*last_element;

	if (lst != 0)
	{
		if (*lst == 0)
			*lst = new;
		else
		{
			last_element = ft_lstlastoken(*lst);
			last_element->next = new;
			new->prev = last_element;
		}
	}
}
