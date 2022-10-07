/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_rdr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridrissi <ridrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 17:29:46 by ridrissi          #+#    #+#             */
/*   Updated: 2022/08/27 17:29:57 by ridrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

void	ft_lstadd_back_rdr(t_rdr **lst, t_rdr *new)
{
	t_rdr	*last_element;

	if (lst != 0)
	{
		if (*lst == 0)
			*lst = new;
		else
		{
			last_element = ft_lstlast_rdr(*lst);
			last_element->next = new;
		}
	}
}
