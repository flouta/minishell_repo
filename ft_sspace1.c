/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sspace1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridrissi <ridrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 16:44:38 by ridrissi          #+#    #+#             */
/*   Updated: 2022/08/27 16:44:50 by ridrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_sspace1(char **s, t_token **token)
{
	int	i;

	i = 0;
	while (i <= len_s(s) - 1)
		ft_lstadd_backtoken(token, ft_lstnewtoken(TOKEN_STR, s[i++]));
}
