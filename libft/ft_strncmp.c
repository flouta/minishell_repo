/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flouta <flouta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 22:17:28 by flouta            #+#    #+#             */
/*   Updated: 2022/08/29 17:02:33 by flouta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp( char *s1, char *s2)
{
	unsigned int	i;
	unsigned int	n;

	if (!s1 || !s2)
		return (-1);
	n = max_len(s1, s2);
	i = 0;
	if (n == 0)
		return (0);
	while ((s1[i] != '\0' && s2[i] != '\0') && (s1[i] == s2[i]) && i < n - 1)
		i++;
	return ((unsigned char)s1[i] - s2[i]);
}
