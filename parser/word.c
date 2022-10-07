/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridrissi <ridrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 16:37:08 by ridrissi          #+#    #+#             */
/*   Updated: 2022/09/09 18:50:50 by ridrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

char	*word(t_lexer **str)
{
	char	*s;
	char	*s1;
	char	*s2;
	void	*p;

	s = malloc(2 * sizeof(char));
	s1 = malloc(1 * sizeof(char));
	s[1] = '\0';
	s1[0] = '\0';
	while (word_range((*str)->content[(*str)->i]))
	{
		s[0] = (*str)->content[(*str)->i];
		s2 = ft_strjoin(s1, s);
		free(s1);
		s1 = s2;
		p = *str;
		*str = init_lexer((*str)->content, (*str)->i + 1);
		free(p);
	}
	free (s);
	return (s2);
}
