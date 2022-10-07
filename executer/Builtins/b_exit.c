/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_exit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flouta <flouta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 15:19:30 by flouta            #+#    #+#             */
/*   Updated: 2022/08/29 17:13:01 by flouta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/minishell.h"
int	check_exit(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (0);
		i++;
	}
	return (1);
}

void	non_umeric(char **arg)
{
	printf("exit\n");
	error_msg(arg[1], ": numeric argument required\n");
	g_var.exit_code = 255;
	exit(g_var.exit_code % 256);
}

void	many_arg(void)
{
	printf("exit\n");
	error_msg("exit", ": too many arguments\n");
	g_var.exit_code = 1;
}

void	b_exit(char **arg)
{
	if (!arg[1])
	{
		printf("exit\n");
		g_var.exit_code = 0;
		exit(g_var.exit_code % 256);
	}
	else
	{
		if (!check_exit(arg[1]))
			non_umeric(arg);
		else
		{
			if (!arg[2])
			{
				printf("exit\n");
				g_var.exit_code = ft_atoi(arg[1]);
				exit(g_var.exit_code % 256);
			}
			else
			{
				many_arg();
				return ;
			}
		}
	}
}
