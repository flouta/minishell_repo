/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_linee.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridrissi <ridrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 16:27:06 by ridrissi          #+#    #+#             */
/*   Updated: 2022/09/09 19:02:32 by ridrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*expand_linee(char *line)
{
	char	*s;
	int		i;
	void	*p;

	i = 0;
	s = (char *) malloc(sizeof(char) * 1);
	s[0] = '\0';
	while (line[i] != '\0')
	{
		if (checkr(line[i], line[i + 1]))
			addexp(line, &i, &s);
		else
		{
			p = s;
			s = addit(s, line[i]);
			free(p);
			i++;
		}
	}
	free(line);
	return (s);
}
