/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_sspace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridrissi <ridrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 16:46:14 by ridrissi          #+#    #+#             */
/*   Updated: 2022/09/09 18:54:47 by ridrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	no_sspace(char **line, t_token **token, char **s)
{
	char	*join;
	int		i;
	void	*tmp;

	i = 0;
	if (len_s(s) > 1)
	{
		tmp = s[i];
		join = ft_strjoin(*line, s[i++]);
		free(tmp);
		ft_lstadd_backtoken(token, ft_lstnewtoken(TOKEN_STR, join));
		while (s[i + 1] != 0)
			ft_lstadd_backtoken(token, ft_lstnewtoken(TOKEN_STR, s[i++]));
		free(*line);
		*line = s[i];
	}
	else if (len_s(s) == 1)
	{
		tmp = s[i];
		join = ft_strjoin(*line, s[i]);
		free(*line);
		*line = join;
		free(tmp);
	}
}
