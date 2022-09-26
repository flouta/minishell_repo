/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_cmd_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridrissi <ridrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 18:22:21 by ridrissi          #+#    #+#             */
/*   Updated: 2022/09/09 17:46:53 by ridrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_cmd_str(char **str, char *cmd)
{
	int	len;

	len = 0;
	if (cmd)
	{
		len = ft_strlen(cmd);
		str[0] = (char *) malloc(sizeof(char) * (len + 1));
		ft_strcpy(str[0], cmd);
	}
}
