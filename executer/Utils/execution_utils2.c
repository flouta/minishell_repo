/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flouta <flouta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 17:33:23 by flouta            #+#    #+#             */
/*   Updated: 2022/09/09 23:26:36 by flouta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/minishell.h"
void	error_msg(char *cmd, char *msg)
{
	char	*msg1;
	char	*msg2;

	msg1 = ft_strjoin("minishell: ", cmd);
	msg2 = ft_strjoin(msg1, msg);
	free(msg1);
	ft_putstr_fd(msg2, 2);
	free(msg2);
}

int	is_empty(char *str, char n)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != n)
			return (-1);
		i++;
	}
	return (1);
}

void	modify_env(char *var, char *path)
{
	t_env	*found;

	found = list_srch(var);
	if (found)
	{
		free(found->value);
		if (!path)
			found->value = getcwd(NULL, PATH_MAX);
		else
			found->value = path;
	}
}

void	free_2d(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
