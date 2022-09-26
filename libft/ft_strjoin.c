/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flouta <flouta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 23:38:03 by flouta            #+#    #+#             */
/*   Updated: 2022/09/01 19:33:27 by flouta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ptr;
	size_t	l;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s2 == NULL)
		return (s1);
	l = ft_strlen(s1) + ft_strlen(s2) + 1;
	ptr = (char *)malloc(l * sizeof(char));
	if (!ptr)
		return (NULL);
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		ptr[i++] = s2[j];
		j++;
	}
	ptr[i] = 0;
	return (ptr);
}
