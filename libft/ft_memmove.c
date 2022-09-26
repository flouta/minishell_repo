/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flouta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 04:19:41 by flouta            #+#    #+#             */
/*   Updated: 2021/11/24 19:35:38 by flouta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*destcpy;
	unsigned char	*source;

	source = (unsigned char *)src;
	destcpy = (unsigned char *) dst;
	if (source < destcpy)
	{
		while (len--)
			destcpy[len] = source[len];
	}
	else
		destcpy = ft_memcpy(dst, src, len);
	return (destcpy);
}
