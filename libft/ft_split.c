/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flouta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 00:04:23 by flouta            #+#    #+#             */
/*   Updated: 2021/11/25 18:47:11 by flouta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	word_count(char const *s, char c)
{
	int	num;
	int	i;

	num = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			num++;
		i++;
	}
	return (num);
}

int	ft_len(const char *str, char c)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[i] != c && str[i])
	{
		len++;
		i++;
	}
	return (len);
}

char	*alc(const char *str, int len)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = (char *)malloc(sizeof(char) * len + 1);
	if (!ptr)
		return (NULL);
	while (i < len)
	{
		ptr[i] = *(str + i);
		i++;
	}
	ptr[i] = 0;
	return (ptr);
}

char	**ft_free(char **ptr, int i)
{	
	i--;
	while (i >= 0)
	{
		free(ptr[i]);
		i--;
	}
	free(ptr);
	return (NULL);
}

char	**ft_split(char const *str, char c)
{
	char	**ptr;
	int		i;
	int		j;
	int		len;

	j = 0;
	i = -1;
	if (!str)
		return (NULL);
	ptr = (char **)malloc((word_count(str, c) + 1) * sizeof(char *));
	if (!ptr)
		return (NULL);
	while (str[++i])
	{
		if (str[i] != c)
		{
			len = ft_len(&str[i], c);
			ptr[j] = alc(&str[i], len);
			if (!ptr[j++])
				return (ft_free(ptr, --j));
			i += (len - 1);
		}
	}
	ptr[j] = 0;
	return (ptr);
}
