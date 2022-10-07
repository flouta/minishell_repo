/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_expand.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridrissi <ridrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 16:49:27 by ridrissi          #+#    #+#             */
/*   Updated: 2022/09/09 18:53:11 by ridrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

int	split_expand(char **line, char *str, t_token **token)
{
	int		start_space;

	start_space = 0;
	if ( str && str[0] == ' ')
		start_space = 1;
	
	if (start_space == 1 && *line[0] != '\0')
	{
		ft_lstadd_backtoken(token, ft_lstnewtoken(TOKEN_STR, ft_strdup(*line)));
		*line[0] = '\0';
	}
	return (split_part(line, str, token, start_space));
}
