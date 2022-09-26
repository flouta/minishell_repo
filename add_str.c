/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridrissi <ridrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 17:12:03 by ridrissi          #+#    #+#             */
/*   Updated: 2022/09/09 17:47:15 by ridrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	add_str(t_lexer **line, int quote, t_token **token, int *valid)
{
	char	*str;
	int		keep_up;
	int		expd;

	str = ft_init(line, &expd, &keep_up);
	while (g_var.b)
	{
		while ((*line)->c != quote && (*line)->c != '\0' && keep_up)
		{
			ft_fctn4(line, &quote, valid);
			if (assign(&expd, ft_fctn9(line, quote, token, &str)) == -4)
				return (0);
			if (expd == 1)
				ft_fctn3(line, &quote, valid);
			if (expd == 0)
			{
				ft_fctn1(line, valid, &keep_up);
				if (keep_up)
					ft_fctn2(line, &str, valid, &quote);
			}	
		}
		ft_fctn10(line, &quote, valid);
	}
	ft_fctn11(str, token);
	return (1);
}
