/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridrissi <ridrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 16:34:35 by ridrissi          #+#    #+#             */
/*   Updated: 2022/09/09 16:34:48 by ridrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*addit(char *s, char c)
{
	char	*str;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	len = ft_strlen(s);
	str = (char *) malloc(sizeof(char) * (len + 2));
	str[len + 1] = '\0';
	while (s[i] != '\0')
	{
		str[j] = s[i];
		i++;
		j++;
	}
	str[j] = c;
	return (str);
}
