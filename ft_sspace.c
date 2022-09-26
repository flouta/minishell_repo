/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sspace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridrissi <ridrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 16:47:13 by ridrissi          #+#    #+#             */
/*   Updated: 2022/08/27 16:47:35 by ridrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_sspace(char **line, t_token **token, char **s)
{
	int	i;

	i = 0;
	if (len_s(s) > 1)
	{
		while (s[i + 1] != 0)
			ft_lstadd_backtoken(token, ft_lstnewtoken(TOKEN_STR, s[i++]));
	}
	free(*line);
	*line = s[i];
}
