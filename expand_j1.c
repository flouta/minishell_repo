/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_j1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridrissi <ridrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 16:32:21 by ridrissi          #+#    #+#             */
/*   Updated: 2022/09/09 19:03:37 by ridrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	expand_j1(char *line, int *i, char **s)
{
	char	*s1;
	char	*p;
	int		expand;
	t_env	*actuel;

	s1 = 0;
	expand = 0;
	actuel = g_var.env;
	if (check_range(line[*i]))
	{
		s1 = wordd1(line, i);
		while (actuel != 0 && !expand)
		{	
			if (!ft_strcmp(actuel->key, s1))
			{
				p = *s;
				*s = ft_strjoin(p, actuel->value);
				free(p);
				expand++;
			}
			actuel = actuel->next;
		}
		free(s1);
	}
}
