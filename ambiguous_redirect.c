/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambiguous_redirect.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridrissi <ridrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 16:42:39 by ridrissi          #+#    #+#             */
/*   Updated: 2022/09/09 19:10:04 by ridrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ambiguous_redirect(t_token **token, char **s, char **line)
{
	void	*p;

	if (*token && (ft_lstlastoken(*token)->e_tp == TOKEN_IN
			|| ft_lstlastoken(*token)->e_tp == TOKEN_OUT
			|| ft_lstlastoken(*token)->e_tp == TOKEN_APPEND
			|| ft_lstlastoken(*token)->e_tp == TOKEN_HEREDOC)
		&& len_s(s) > 1)
	{
		p = *line;
		ft_lstlastoken(*token)->ambg = 1;
	}
	return (1);
}
