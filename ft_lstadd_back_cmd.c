/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_cmd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridrissi <ridrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 17:23:02 by ridrissi          #+#    #+#             */
/*   Updated: 2022/08/27 17:23:16 by ridrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_lstadd_back_cmd(t_cmd **lst, t_cmd *new)
{
	t_cmd	*last_element;

	if (lst != 0)
	{
		if (*lst == 0)
			*lst = new;
		else
		{
			last_element = ft_lstlast_cmd(*lst);
			last_element->next = new;
		}
	}
}
