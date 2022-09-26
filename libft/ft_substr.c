/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flouta <flouta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 23:34:41 by flouta            #+#    #+#             */
/*   Updated: 2022/08/29 17:03:25 by flouta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char *s, size_t start, int len)
{
	int				l;
	char			*sub;
	int				i;
	unsigned int	x;

	x = start;
	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	l = 0;
	while (s[x++] && l < len)
		l++;
	sub = (char *)malloc((l + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	l = start;
	while (s[l] && i < len)
	{
		sub[i++] = s[l];
		l++;
	}
	sub[i] = 0;
	return (sub);
}
