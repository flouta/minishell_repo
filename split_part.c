/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_part.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridrissi <ridrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 16:48:07 by ridrissi          #+#    #+#             */
/*   Updated: 2022/09/09 18:53:03 by ridrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	split_part(char **line, char *str, t_token **token, int start_space)
{
	char	**s;
	int		end_space;

	end_space = 0;
	if (ft_strlen(str) && str[ft_strlen(str) - 1] == ' ')
		end_space = 1;
	s = ft_split(str, ' ');
	if (ambiguous_redirect(token, s, line) == 0)
		return (0);
	if (end_space == 0)
	{
		if (start_space == 0)
			no_sspace(line, token, s);
		else if (start_space == 1)
			ft_sspace(line, token, s);
	}
	else if (end_space == 1)
	{
		if (start_space == 0)
			no_sspace1(line, token, s);
		else if (start_space == 1)
			ft_sspace1(s, token);
	}
	free(s);
	return (1);
}
