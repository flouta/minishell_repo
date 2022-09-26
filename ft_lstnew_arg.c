/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridrissi <ridrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 17:24:06 by ridrissi          #+#    #+#             */
/*   Updated: 2022/08/27 17:24:51 by ridrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_args	*ft_lstnew_arg(char *str)
{
	t_args	*new;

	new = malloc (sizeof(t_args));
	if (new == 0)
		return (0);
	new->arg = str;
	new->next = 0;
	return (new);
}
