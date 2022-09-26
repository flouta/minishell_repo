/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flouta <flouta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 15:33:46 by flouta            #+#    #+#             */
/*   Updated: 2022/09/01 19:29:05 by flouta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_lst(t_env *head)
{
	t_env	*tmp;

	tmp = NULL;
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

void	display_export(void)
{
	t_env	*dup;
	t_env	*head;

	head = NULL;
	dup = copy_list(g_var.env);
	dup = sort_list(dup);
	head = dup;
	while (head)
	{
		if (head->value)
		{
			printf("declare -x %s=\"%s\"\n", head->key, head->value);
			head = head->next;
		}
		else
		{
			printf("declare -x %s\n", head->key);
			head = head->next;
		}
	}
	free_lst(dup);
}

void	change_dir(char *path)
{
	char	*pathh;

	pathh = getcwd(NULL, PATH_MAX);
	if (chdir(path) == -1)
	{
		perror("CD");
		g_var.exit_code = 1;
		return ;
	}
	else
	{
		modify_env("OLDPWD", pathh);
		modify_env("PWD", NULL);
	}
}

void	cd_home(void)
{
	t_env	*found;

	found = list_srch("HOME");
	if (!found)
	{
		error_msg("cd", ": HOME not set\n");
		g_var.exit_code = 1;
		return ;
	}
	else
		change_dir(found->value);
}

int	check_opt(char **arg)
{
	int	i;

	i = 1;
	while (arg[i])
	{
		if ((arg[i][0] == '-' && arg[i][1] == '\0') \
		|| (arg[i][0] != '-' \
		|| is_empty(arg[i] + 1, 'n') == -1))
			return (i);
		i++;
	}
	return (i);
}
