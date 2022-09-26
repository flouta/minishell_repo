/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fctn10.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridrissi <ridrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 17:06:57 by ridrissi          #+#    #+#             */
/*   Updated: 2022/08/27 17:07:06 by ridrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_fctn10(t_lexer **line, int *quote, int *valid)
{
	*quote = 0;
	*valid = 0;
	ft_fctn7(line);
	ft_fctn8(line, valid, quote);
}
