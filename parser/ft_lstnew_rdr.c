/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_rdr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridrissi <ridrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 17:25:36 by ridrissi          #+#    #+#             */
/*   Updated: 2022/09/08 15:02:08 by ridrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

t_rdr	*ft_lstnew_rdr(char *str, int type, int flag)
{
	t_rdr	*new;

	new = malloc (sizeof(t_rdr));
	if (new == 0)
		return (0);
	new->e_tp = type;
	new->content = str;
	new->expd_flag = flag;
	new->err_flag = g_var.ambgs;
	new->next = 0;
	return (new);
}
