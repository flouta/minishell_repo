/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_args_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridrissi <ridrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 18:23:59 by ridrissi          #+#    #+#             */
/*   Updated: 2022/09/09 17:47:03 by ridrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_args_str(char **str, t_args *args, int i)
{
	int		len;
	t_args	*actuel;

	len = 0;
	actuel = args;
	while (actuel)
	{
		len = ft_strlen(actuel->arg);
		str[i] = (char *) malloc(sizeof(char) * (len + 1));
		ft_strcpy(str[i], actuel->arg);
		i++;
		actuel = actuel->next;
	}
}
