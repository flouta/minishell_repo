/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_dollar_s2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridrissi <ridrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 16:38:55 by ridrissi          #+#    #+#             */
/*   Updated: 2022/09/09 19:05:00 by ridrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	expand_dollar_s2(int *i, char **s)
{
	void	*p;
	char	*s1;
	char	*excode;

	*i += 1;
	s1 = *s;
	excode = ft_itoa(g_var.exit_code);
	p = *s;
	*s = ft_strjoin(s1, excode);
	free(p);
	free(excode);
}
