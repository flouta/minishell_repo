/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_echo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flouta <flouta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 15:17:00 by flouta            #+#    #+#             */
/*   Updated: 2022/09/09 23:32:02 by flouta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	b_echo(char **arg)
{
	int	i;
	int	d;

	i = check_opt(arg);
	d = i;
	if (arg[i])
	{
		ft_putstr_fd(arg[i], 1);
		i++;
		while (arg[i])
		{
			write(1, " ", 1);
			ft_putstr_fd(arg[i], 1);
			i++;
		}
	}
	if (d == 1)
		ft_putstr_fd("\n", 1);
}
