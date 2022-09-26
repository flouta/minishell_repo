/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flouta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 21:26:29 by flouta            #+#    #+#             */
/*   Updated: 2021/11/25 18:45:07 by flouta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	src_l;
	size_t	des_l;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	src_l = ft_strlen(src);
	des_l = ft_strlen(dst);
	while (src[j] != '\0' && (des_l + i) < dstsize - 1)
	{
		dst[des_l + i] = src[j];
		j++;
		i++;
	}
	dst[des_l + i] = '\0';
	if (dstsize > des_l)
		return (src_l + des_l);
	else
		return (src_l + dstsize);
}
