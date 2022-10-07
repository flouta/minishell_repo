/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flouta <flouta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 18:58:31 by flouta            #+#    #+#             */
/*   Updated: 2022/09/09 23:27:10 by flouta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/minishell.h"
void	parent_waiting(int pid)
{
	int	status;

	status = 0;
	if (pid != 0)
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
			g_var.exit_code = WEXITSTATUS(status);
		else if (WIFSIGNALED(status))
			g_var.exit_code = WTERMSIG(status) + 128;
		while (wait(NULL) > 0)
			;
	}
}

void	init_files(t_cmd *input)
{
	t_cmd	*head;

	head = input;
	while (head)
	{
		head->in_out = open_files(head->rdr);
		head = head->next;
	}
}

void	execution(t_cmd *input)
{
	int	pid;

	pid = 0;
	if (g_var.env)
	{
		g_var.exit_code = 0;
		g_var.herd_flag = 0;
		g_var.stdi_o = stdin_stdout();
		if (open_herd(input) == 1)
		{
			init_files(input);
			if (input && !input->next)
			{
				if (input->cmd)
					pid = simple_command(input);
			}
			else
				pid = pipe_line(input);
			parent_waiting(pid);
		}
		backup_i_o(g_var.stdi_o);
		free(g_var.stdi_o);
	}
}
