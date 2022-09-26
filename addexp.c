/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addexp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridrissi <ridrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 16:30:16 by ridrissi          #+#    #+#             */
/*   Updated: 2022/09/09 16:30:26 by ridrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	addexp(char *line, int *i, char **s)
{
	*i += 1;
	if (line[*i] == '?')
		expand_dollar_s2(i, s);
	else if (!(line[*i] >= '0' && line[*i] <= '9'))
		expand_j1(line, i, s);
	else if ((line[*i] >= '0' && line[*i] <= '9'))
		*i += 1;
}
