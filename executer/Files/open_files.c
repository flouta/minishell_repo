/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flouta <flouta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 16:11:45 by flouta            #+#    #+#             */
/*   Updated: 2022/09/09 23:33:05 by flouta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/minishell.h"
int	*append_file(t_rdr *head, int *in_out)
{
	if (in_out[1] != 1)
		close(in_out[1]);
	in_out[1] = open(head->content, O_APPEND | O_CREAT | O_RDWR, 0644);
	if (in_out[1] < 0)
	{
		perror("FILE");
		in_out[2] = -1;
	}
	return (in_out);
}

int	*in_herd(t_rdr *head, int *in_out)
{
	if (in_out[0] != 0)
		close(in_out[0]);
	in_out[0] = head->h_fd;
	if (in_out[0] < 0)
	{
		perror("FILE");
		in_out[2] = -1;
	}
	return (in_out);
}

int	*file_type(t_rdr *head, int *in_out)
{
	if (head->e_tp == OUT)
		in_out = out_file(head, in_out);
	if (head->e_tp == IN)
		in_out = in_file(head, in_out);
	if (head->e_tp == OUT_APPEND)
		in_out = append_file(head, in_out);
	if (head->e_tp == IN_HEREDOC)
		in_out = in_herd(head, in_out);
	return (in_out);
}

int	open_herd(t_cmd *cmd)
{
	t_cmd	*head;
	t_rdr	*file;

	head = cmd;
	while (head)
	{
		file = head->rdr;
		while (file)
		{
			if (file->e_tp == IN_HEREDOC)
				file->h_fd = open_heredoc(file);
			if (g_var.herd_flag == 1)
				return (-1);
			file = file->next;
		}
		head = head->next;
	}
	return (1);
}

int	*open_files(t_rdr *files)
{
	t_rdr	*head;
	int		*in_out;

	in_out = NULL;
	head = files;
	in_out = malloc(sizeof(int) * 3);
	if (!in_out)
		error_handling("OVERFLOW\n");
	in_out[0] = 0;
	in_out[1] = 1;
	in_out[2] = 1;
	while (head)
	{
		in_out = file_type(head, in_out);
		if (in_out[2] == -1)
			break ;
		head = head->next;
	}
	return (in_out);
}
