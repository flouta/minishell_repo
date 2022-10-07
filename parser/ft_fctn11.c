/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fctn11.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridrissi <ridrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 17:07:37 by ridrissi          #+#    #+#             */
/*   Updated: 2022/08/27 17:07:56 by ridrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/minishell.h"

void	ft_fctn11(char *str, t_token **token)
{
	if (str && str[0] != '\0')
		ft_lstadd_backtoken(token, ft_lstnewtoken(TOKEN_STR, str));
	else if (str[0] == '\0')
		free(str);
}
