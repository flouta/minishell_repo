/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_sspace1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridrissi <ridrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 16:43:41 by ridrissi          #+#    #+#             */
/*   Updated: 2022/09/09 18:54:40 by ridrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	no_sspace1(char **line, t_token **token, char **s)
{
	char	*join;
	int		i;
	void	*tmp;

	i = 0;
	tmp = s[i];
	join = ft_strjoin(*line, s[i++]);
	free(tmp);
	ft_lstadd_backtoken(token, ft_lstnewtoken(TOKEN_STR, join));
	*line[0] = '\0';
	while (i <= len_s(s) - 1)
		ft_lstadd_backtoken(token, ft_lstnewtoken(TOKEN_STR, s[i++]));
}
