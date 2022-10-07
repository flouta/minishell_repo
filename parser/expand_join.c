/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_join.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridrissi <ridrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 16:53:24 by ridrissi          #+#    #+#             */
/*   Updated: 2022/09/09 18:59:16 by ridrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

int	expand_join(char **line, t_lexer **str, int quote, t_token **token)
{
	t_env	*actuel;
	int		expand;

	expand = 0;
	actuel = g_var.env;
	if (check_range((*str)->content[(*str)->i]))
	{
		if (g_var.s2 != 0)
		{
			free(g_var.s2);
			g_var.s2 = 0;
		}
		g_var.s2 = word(str);
		while (actuel != 0 && !expand)
		{	
			if (!ft_strcmp(actuel->key, g_var.s2))
			{
				if (joining(quote, line, actuel->value, token) == 0)
					return (0);
				expand++;
			}
			actuel = actuel->next;
		}
	}
	return (1);
}
