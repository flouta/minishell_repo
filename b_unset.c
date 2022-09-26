/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_unset.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flouta <flouta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 15:32:48 by flouta            #+#    #+#             */
/*   Updated: 2022/09/01 17:23:12 by flouta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_unset(char *arg)
{
	if (arg[0] == '\0' || is_empty(arg, ' ') == 1)
	{
		error_msg(arg, ": not a valid identifier\n");
		g_var.exit_code = 1;
		return (1);
	}
	if (check_key(arg) == -1)
	{
		g_var.exit_code = 1;
		return (1);
	}
	return (0);
}

void	free_var(t_env *head)
{
	free(head->key);
	free(head->value);
	free(head);
}

void	delete_var(char *arg, t_env *head)
{
	t_env	*prev;

	prev = NULL;
	if (ft_strncmp(head->key, arg) == 0)
	{
		g_var.env = head->next;
		free_var(head);
	}
	else
	{
		while (head && ft_strncmp(head->key, arg) != 0)
		{
			prev = head;
			head = head->next;
		}
		if (!head)
			return ;
		if (head && ft_strncmp(head->key, arg) == 0)
		{
			prev->next = head->next;
			free_var(head);
		}
	}
}

void	b_unset(char **arg)
{
	int		i;
	t_env	*head;

	i = 0;
	head = g_var.env;
	while (arg[++i])
	{
		head = g_var.env;
		if (check_unset(arg[i]) == 1)
			continue ;
		delete_var(arg[i], head);
	}
}
