/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridrissi <ridrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 17:20:58 by ridrissi          #+#    #+#             */
/*   Updated: 2022/09/02 19:08:59 by ridrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*ft_lstnew_cmd(void)
{
	t_cmd	*new;

	new = malloc (sizeof(t_cmd));
	if (new == 0)
		return (0);
	new->cmd = 0;
	new->args = 0;
	new->rdr = 0;
	new->arg_arr = 0;
	new->in_out = 0;
	new->next = 0;
	return (new);
}
