/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridrissi <ridrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 19:00:48 by flouta            #+#    #+#             */
/*   Updated: 2022/09/04 17:56:03 by ridrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/minishell.h"
void	run_child(t_cmd *input, int *fd, int last_in, t_cmd *cmd)
{
	if (input->in_out[2] == -1)
		exit(1);
	dup_child(input, fd, last_in, cmd);
	if (is_builtin(input->cmd) == 1)
	{
		run_builtin(input);
		exit(g_var.exit_code % 256);
	}
	else
	{
		single_command(input);
		exit(g_var.exit_code % 256);
	}	
}

int	close_parent(int *in_out, int last_in, int *fd)
{
	if (last_in != 0)
		close(last_in);
	last_in = fd[0];
	close(fd[1]);
	if (in_out[0] != 0)
		close(in_out[0]);
	if (in_out[1] != 1)
		close(in_out[1]);
	return (last_in);
}

int	pipe_line(t_cmd *cmd)
{
	int		last_in;
	int		fd[2];
	int		pid;
	t_cmd	*input;

	last_in = 0;
	input = cmd;
	pid = 0;
	while (input)
	{
		if (input->cmd)
		{
			if (input->next)
				pipe(fd);
			g_var.sig_flag = 'c';
			pid = fork();
			if (pid == -1)
				error_handling("ERROR : FORK\n");
			if (pid == 0)
				run_child(input, fd, last_in, cmd);
			last_in = close_parent(input->in_out, last_in, fd);
		}
		input = input->next;
	}
	return (pid);
}
