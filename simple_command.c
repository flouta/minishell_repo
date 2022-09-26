/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flouta <flouta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 18:54:47 by flouta            #+#    #+#             */
/*   Updated: 2022/09/09 23:21:15 by flouta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	single_command(t_cmd *input)
{
	char	**env;
	int		test;

	env = NULL;
	test = 0;
	env = lst_to_arr();
	signal(SIGQUIT, SIG_DFL);
	if (get_path(input) == 1)
	{
		if (execve(input->cmd, input->arg_arr, env) == -1)
		{
			g_var.exit_code = 126;
			free_2d(env);
			perror("EXEC");
		}
	}
}

int	*stdin_stdout(void)
{
	int	*stdi_o;

	stdi_o = malloc(sizeof(int) * 2);
	if (!stdi_o)
		error_handling("OVERFLOW\n");
	stdi_o[0] = dup(0);
	if (stdi_o[0] == -1)
		error_handling("DUP");
	stdi_o[1] = dup(1);
	if (stdi_o[0] == -1)
		error_handling("DUP");
	return (stdi_o);
}

void	backup_i_o(int *stdi_o)
{
	dup2(stdi_o[0], 0);
	dup2(stdi_o[1], 1);
}

void	child_process(t_cmd *input)
{
	single_command(input);
	exit(g_var.exit_code % 256);
}

int	simple_command(t_cmd *input)
{
	int	pid;

	pid = 0;
	if (input->in_out[2] != 1)
		g_var.exit_code = 1;
	else
	{
		dup_2(input->in_out);
		if (is_builtin(input->cmd))
			run_builtin(input);
		else
		{
			g_var.sig_flag = 'c';
			pid = fork();
			if (pid == 0)
				child_process(input);
		}
	}
	return (pid);
}
