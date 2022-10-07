/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridrissi <ridrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 16:24:56 by ridrissi          #+#    #+#             */
/*   Updated: 2022/08/27 19:25:38 by ridrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	if(!s)
		return 0;
	while (s[len] != '\0')
		len++;
	return (len);
}
