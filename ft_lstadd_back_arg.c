/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_arg.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridrissi <ridrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 17:34:57 by ridrissi          #+#    #+#             */
/*   Updated: 2022/08/27 17:35:07 by ridrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_lstadd_back_arg(t_args **lst, t_args *new)
{
	t_args	*last_element;

	if (lst != 0)
	{
		if (*lst == 0)
			*lst = new;
		else
		{
			last_element = ft_lstlast_arg(*lst);
			last_element->next = new;
		}
	}
}
