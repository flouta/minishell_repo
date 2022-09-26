/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flouta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 23:42:53 by flouta            #+#    #+#             */
/*   Updated: 2021/11/24 22:33:06 by flouta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_find(char const *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	first_index(char const *s1, char const *set)
{
	int	i;

	i = 0;
	while (s1[i] && ft_find(set, s1[i]))
		i++;
	return (i);
}

int	last_index(char const *s1, char const *set)
{
	size_t	l;

	l = ft_strlen(s1);
	while (ft_find(set, s1[l - 1]))
		l--;
	return (l);
}

int	count(char const *s, int start, int last)
{
	int	c;

	c = 0;
	while (s[start] && start <= last)
	{
		start++;
		c++;
	}
	return (c);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	char	*trim;
	int		first;
	int		last;

	i = 0;
	if (!s1 || !set)
		return (NULL);
	first = first_index(s1, set);
	last = last_index(s1, set);
	trim = (char *)malloc(count(s1, first, last) * sizeof(char));
	if (!trim)
		return (NULL);
	while (first < last)
	{
		trim[i] = s1[first++];
		i++;
	}
	trim[i] = 0;
	return (trim);
}
