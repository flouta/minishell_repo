/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flouta <flouta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 21:06:14 by flouta            #+#    #+#             */
/*   Updated: 2022/08/29 17:13:26 by flouta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdcpy(char *dst, char *src, char delimiter)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0' && src[i] != delimiter)
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}

char	*ft_strscpy(char *dst, char *src, int i)
{
	while (src[i] != '\0' && i != 0)
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}
