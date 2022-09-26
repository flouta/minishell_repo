/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expdd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridrissi <ridrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 16:24:23 by ridrissi          #+#    #+#             */
/*   Updated: 2022/09/09 16:25:24 by ridrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_expdd(char *line)
{
	char	*s;

	s = line;
	if (check_lds(line))
	{
		return (expand_linee(line));
	}
	return (s);
}
