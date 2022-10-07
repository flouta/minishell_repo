/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flouta <flouta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 16:12:29 by flouta            #+#    #+#             */
/*   Updated: 2022/08/29 16:33:39 by flouta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/minishell.h"
char	*to_mini(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
		i++;
	}
	return (str);
}

int	is_builtin(char *cmd)
{
	if (cmd && cmd[0])
	{
		if (ft_strncmp("cd", cmd) == 0)
			return (1);
		if (ft_strncmp("export", cmd) == 0)
			return (1);
		if (ft_strncmp("unset", cmd) == 0)
			return (1);
		if (ft_strncmp("exit", cmd) == 0)
			return (1);
		cmd = to_mini(cmd);
		if (ft_strncmp("echo", cmd) == 0)
			return (1);
		if (ft_strncmp("env", cmd) == 0)
			return (1);
		if (ft_strncmp("pwd", cmd) == 0)
			return (1);
	}
	return (0);
}

void	run_builtin(t_cmd *node)
{
	if (node->cmd && node->cmd[0])
	{
		if (ft_strncmp("cd", node->cmd) == 0)
			b_cd(node->arg_arr);
		if (ft_strncmp("export", node->cmd) == 0)
			b_export(node->arg_arr);
		if (ft_strncmp("unset", node->cmd) == 0)
			b_unset(node->arg_arr);
		if (ft_strncmp("exit", node->cmd) == 0)
			b_exit(node->arg_arr);
		node->cmd = to_mini(node->cmd);
		if (ft_strncmp("echo", node->cmd) == 0)
			b_echo(node->arg_arr);
		if (ft_strncmp("env", node->cmd) == 0)
			b_env(node->arg_arr);
		if (ft_strncmp("pwd", node->cmd) == 0)
			b_pwd();
	}
}
