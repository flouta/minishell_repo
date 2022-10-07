/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flouta <flouta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 17:40:13 by flouta            #+#    #+#             */
/*   Updated: 2022/09/01 17:40:14 by flouta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/minishell.h"
void	first_child(int *in_out, int *fd)
{
	close(fd[0]);
	if (in_out[0] != 0)
	{
		dup2(in_out[0], 0);
		close(in_out[0]);
	}
	if (in_out[1] != 1)
	{
		dup2(in_out[1], 1);
		close(in_out[1]);
		close(fd[1]);
	}
	else
	{
		dup2(fd[1], 1);
		close(fd[1]);
	}
}

void	mid_child(int *in_out, int last_in, int *fd)
{
	close(fd[0]);
	if (in_out[0] != 0)
	{
		dup2(in_out[0], 0);
		close(in_out[0]);
	}
	else
	{
		dup2(last_in, 0);
		close(last_in);
	}
	if (in_out[1] != 1)
	{
		dup2(in_out[1], 1);
		close(in_out[1]);
		close(fd[1]);
	}
	else
	{
		dup2(fd[1], 1);
		close(fd[1]);
	}	
}

void	last_child(int *in_out, int last_in)
{
	if (in_out[0] != 0)
	{
		dup2(in_out[0], 0);
		close(in_out[0]);
	}
	else
	{
		dup2(last_in, 0);
		close(last_in);
	}
	if (in_out[1] != 1)
	{
		dup2(in_out[1], 1);
		close(in_out[1]);
	}		
}

void	dup_child(t_cmd *input, int *fd, int last_in, t_cmd *cmd)
{
	if (input == cmd)
		first_child(input->in_out, fd);
	else if (input->next == NULL)
		last_child(input->in_out, last_in);
	else
		mid_child(input->in_out, last_in, fd);
}
