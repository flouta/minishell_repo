/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_util3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flouta <flouta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 17:31:03 by flouta            #+#    #+#             */
/*   Updated: 2022/09/01 18:54:16 by flouta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	dup_2(int *i_o)
{
	dup2(i_o[0], 0);
	dup2(i_o[1], 1);
	if (i_o[0] != 0)
		close(i_o[0]);
	if (i_o[1] != 1)
		close(i_o[1]);
}

char	**split_path(char *cmd)
{
	t_env	*path_var;
	char	**path;

	path = NULL;
	path_var = list_srch("PATH");
	if (!path_var)
	{
		error_msg(cmd, ":No such file or directory\n");
		g_var.exit_code = 127;
		return (NULL);
	}
	if (path_var)
		path = ft_split(path_var->value, ':');
	return (path);
}

int	search(char *cmd)
{
	int	i;

	i = 0;
	if (cmd)
	{
		while (cmd[i])
		{
			if (cmd[i] == '/')
				return (1);
			i++;
		}
	}
	return (-1);
}

int	is_directory(char *path)
{
	struct stat	statbuf;

	if (stat(path, &statbuf) != 0)
		return (0);
	if (S_ISDIR(statbuf.st_mode) == 1)
	{
		error_msg(path, ": is a directory\n");
		g_var.exit_code = 126;
		return (1);
	}
	return (0);
}
