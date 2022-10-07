/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   joining.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridrissi <ridrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 16:51:36 by ridrissi          #+#    #+#             */
/*   Updated: 2022/09/09 18:55:36 by ridrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

int	joining(int quote, char **line, char *val, t_token **token)
{
	void	*tmp;
	char	*s;

	s = *line;
	if (quote == 0)
	{
		if (split_expand(line, val, token) == 0)
			return (0);
	}
	else if (quote != 0)
	{
		tmp = *line;
		*line = ft_strjoin(s, val);
		free(tmp);
	}
	return (1);
}
