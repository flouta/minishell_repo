/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridrissi <ridrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 16:17:08 by ridrissi          #+#    #+#             */
/*   Updated: 2022/08/27 19:24:25 by ridrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	iden;

	iden = 0;
	while (iden == 0 && (*s2 != '\0' || *s1 != '\0'))
	{
		iden = *s1 - *s2;
		s1++;
		s2++;
	}
	if (iden < 0)
		iden = -1;
	else if (iden > 0)
		iden = 1;
	return (iden);
}
