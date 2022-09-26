/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flouta <flouta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 18:47:05 by flouta            #+#    #+#             */
/*   Updated: 2022/09/09 23:25:01 by flouta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	heredoc(t_rdr *rdr, int h_fd)
{
	char	*line;
	char	*delimiter;

	delimiter = ft_strjoin(rdr->content, "\n");
	g_var.sig_flag = 'h';
	line = get_line2(0);
	while (ft_strncmp(line, delimiter) != 0 && line)
	{
		if (rdr->expd_flag == 1)
			line = ft_expdd(line);
		ft_putstr_fd(line, h_fd);
		free(line);
		line = get_line2(0);
	}
	free(delimiter);
	free(line);
	dup2(g_var.stdi_o[0], 0);
	close(h_fd);
}

int	open_heredoc(t_rdr *rdr)
{
	int		h_fd;
	char	*name;
	char	*join;

	join = ft_itoa(g_var.her_d);
	name = ft_strjoin("/tmp/in", join);
	free(join);
	h_fd = open(name, O_CREAT | O_WRONLY | O_TRUNC, 0666);
	g_var.her_d++;
	if (h_fd < 0)
	{
		perror("error");
		exit(EXIT_FAILURE);
	}
	heredoc(rdr, h_fd);
	h_fd = open(name, O_RDONLY);
	free(name);
	return (h_fd);
}

int	*out_file(t_rdr *head, int *in_out)
{
	if (in_out[1] != 1)
		close(in_out[1]);
	in_out[1] = open(head->content, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (in_out[1] < 0)
	{
		perror("FILE");
		in_out[2] = -1;
	}
	return (in_out);
}
