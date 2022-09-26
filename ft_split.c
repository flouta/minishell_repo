/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridrissi <ridrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 16:18:11 by ridrissi          #+#    #+#             */
/*   Updated: 2022/09/09 18:55:59 by ridrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	countwords(const char *str, char c)
{
	int	i;
	int	j;
	int	words;

	i = 0;
	j = 0;
	words = 0;
	while ((str[i] != '\0'))
	{
		while (str[i] == c)
			i++;
		while (str[i] != c && str[i] != '\0')
		{
			if (j == 0)
				words++;
			i++;
			j = 1;
		}
		j = 0;
	}
	return (words);
}

size_t	ft_len(const char *str, char c)
{
	size_t	len;

	len = 0;
	while (str[len] != c && str[len] != '\0')
		len++;
	return (len);
}

void	splitit(const char *str, char **strs, char c)
{
	size_t	i;
	size_t	j;
	size_t	len;
	size_t	k;

	i = 0;
	k = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i] == c)
			i++;
		if (str[i] != '\0')
		{
			len = ft_len(&str[i], c);
			strs[k] = (char *) malloc(sizeof(char) * (len + 1));
			while (len > 0)
			{
				strs[k][j++] = str[i++];
				len--;
			}
			strs[k++][j] = '\0';
		}
	}
}

char	**ft_split(const char *str, char c)
{
	int		l;
	char	**strs;

	if (!str)
		return (0);
	l = countwords(str, c);
	strs = (char **) malloc((l + 1) * sizeof(char *));
	if (!strs)
		return (0);
	splitit(str, strs, c);
	strs[l] = 0;
	return (strs);
}
