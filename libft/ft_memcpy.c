/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flouta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 04:11:19 by flouta            #+#    #+#             */
/*   Updated: 2021/11/25 18:44:37 by flouta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*serc;
	char	*dest;

	i = 0;
	if (!dst && !src)
		return (NULL);
	if (dst == src || n == 0)
		return (dst);
	dest = (char *)dst;
	serc = (char *)src;
	while (i < n)
	{
		dest[i] = serc[i];
		i++;
	}
	return (dst);
}
