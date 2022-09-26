/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ardr.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridrissi <ridrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 17:35:45 by ridrissi          #+#    #+#             */
/*   Updated: 2022/09/09 19:00:30 by ridrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ardr(t_rdr **lst, char *s, int tp, int f)
{
	ft_lstadd_back_rdr(lst, ft_lstnew_rdr(s, tp, f));
}
