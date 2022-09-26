/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flouta <flouta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 18:44:29 by flouta            #+#    #+#             */
/*   Updated: 2021/11/25 18:33:11 by flouta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	int		i;
	void	*c;

	i = 0;
	c = malloc(count * size);
	if (!c)
		return (NULL);
	ft_bzero(c, size * count);
	return (c);
}
