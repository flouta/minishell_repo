/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wordd1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridrissi <ridrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 16:33:49 by ridrissi          #+#    #+#             */
/*   Updated: 2022/09/09 16:33:59 by ridrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*wordd1(char *line, int *i)
{
	char	*s;
	void	*p;

	s = malloc(1 * sizeof(char));
	s[0] = '\0';
	while (word_range(line[*i]))
	{
		p = s;
		s = addit(s, line[*i]);
		*i += 1;
		free(p);
	}
	return (s);
}
