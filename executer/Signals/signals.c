/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flouta <flouta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 23:18:48 by flouta            #+#    #+#             */
/*   Updated: 2022/09/09 23:19:57 by flouta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/minishell.h"
void	ctrld_handler(char *str)
{
	if (!str)
		exit(g_var.exit_code);
}

void	c_handler(int sig)
{
	(void)sig;
	if (g_var.sig_flag == 'c')
		write(1, "^C\n", 3);
	if (g_var.sig_flag == 'r')
	{
		g_var.exit_code = 1;
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	else if (g_var.sig_flag == 'h')
	{
		g_var.exit_code = 1;
		g_var.herd_flag = 1;
		close(0);
		write(1, "\n", 1);
	}
}

void	q_handler(int sig)
{
	(void)sig;
	if (g_var.sig_flag == 'c')
		write(1, "^\\Quit\n", 8);
	else if (g_var.sig_flag == 'r')
	{
		rl_on_new_line();
		rl_redisplay();
	}
}
