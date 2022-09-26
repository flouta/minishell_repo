/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flouta <flouta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 15:51:09 by flouta            #+#    #+#             */
/*   Updated: 2022/09/01 19:37:04 by flouta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	access_error(t_cmd *input)
{
	if (search(input->cmd) == 1 && input->cmd[0])
		error_msg(input->cmd, ": No such file or directory\n");
	else
		error_msg(input->cmd, ": command not found\n");
	g_var.exit_code = 127;
}

int	access_check(t_cmd *input, char *path)
{
	char	*join1;
	char	*join2;

	join1 = NULL;
	join2 = NULL;
	join1 = ft_strjoin(path, "/");
	join2 = ft_strjoin(join1, input->cmd);
	free(join1);
	if (access(join2, F_OK) == 0)
	{
		free(input->cmd);
		input->cmd = ft_strdup(join2);
		free(join2);
		return (1);
	}
	free(join2);
	return (0);
}

int	get_path(t_cmd *input)
{
	char	**path;
	int		i;

	path = NULL;
	i = -1;
	if (input->cmd)
	{
		if (is_directory(input->cmd) == 1)
			return (-1);
		if (search(input->cmd) == 1 && input->cmd[0])
			if (access(input->cmd, F_OK) == 0)
				return (1);
		if (input->cmd[0])
		{
			path = split_path(input->cmd);
			if (path == NULL)
				return (-1);
			while (path[++i])
				if (access_check(input, path[i]) == 1)
					return (1);
			free_2d(path);
		}
	}
	access_error(input);
	return (-1);
}

int	env_len(void)
{
	t_env	*head;
	int		i;

	head = g_var.env;
	i = 0;
	while (head)
	{
		i++;
		head = head->next;
	}
	return (i);
}

char	**lst_to_arr(void)
{
	char	**arr;
	char	*join;
	int		len;
	int		i;
	t_env	*head;

	join = NULL;
	i = 0;
	head = g_var.env;
	len = env_len();
	arr = malloc(sizeof(char *) * (len + 1));
	while (head->next)
	{
		join = ft_strjoin(head->key, "=");
		if (head->value)
			arr[i] = ft_strjoin(join, head->value);
		else
			arr[i] = ft_strdup(join);
		free(join);
		i++;
		head = head->next;
	}
	arr[i] = 0;
	return (arr);
}
