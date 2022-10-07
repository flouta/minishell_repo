/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flouta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 00:14:16 by flouta            #+#    #+#             */
/*   Updated: 2021/11/23 22:38:53 by flouta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	nlen(int n)
{
	int		size;
	long	nbr;

	size = 0;
	nbr = (long) n;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		nbr = -nbr;
		size = 1;
	}
	while (nbr > 0)
	{
		nbr /= 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	int		size;
	char	*ptr;
	long	nbr;

	nbr = (long) n;
	size = nlen(nbr);
	ptr = (char *)malloc(sizeof(char) * size + 1);
	if (!ptr)
		return (NULL);
	ptr[size--] = '\0';
	if (nbr == 0)
		ptr[0] = '0';
	if (nbr < 0)
	{
		nbr = -nbr;
		ptr[0] = '-';
	}
	while (nbr)
	{
		ptr[size--] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (ptr);
}
