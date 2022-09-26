/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flouta <flouta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 17:24:03 by flouta            #+#    #+#             */
/*   Updated: 2022/09/09 23:29:14 by flouta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*list_srch(char *var)
{
	t_env	*head;
	char	*var_key;

	head = g_var.env;
	var_key = get_key(var);
	while (head)
	{
		if (ft_strncmp(head->key, var_key) == 0)
		{
			free(var_key);
			return (head);
		}
		head = head->next;
	}
	free(var_key);
	return (NULL);
}

void	append_value(t_env *found, char *var_value)
{
	char	*new_value;

	new_value = NULL;
	if (!found->value)
		found->value = ft_strdup(var_value);
	else
	{
		new_value = ft_strjoin(found->value, var_value);
		free(found->value);
		found->value = new_value;
	}
	free(var_value);
}

void	overwrite_value(t_env *found, char *var_value)
{
	free(found->value);
	found->value = var_value;
}

int	check_key(char *key)
{
	int	i;

	i = 0;
	if (!ft_isalpha(key[0]) && key[0] != '_')
	{
		error_msg(key, ": not an identifier\n");
		return (-1);
	}
	while (key[i])
	{
		if (!ft_isalnum(key[i]) && key[i] != '_')
		{
			error_msg(key, ": not an identifier\n");
			return (-1);
		}
		i++;
	}
	return (1);
}

char	get_flag(char *arg)
{
	int	i;

	i = 0;
	while (arg[i] && arg[i] != '=')
		i++;
	if (arg[i] == '=' && arg[i - 1] == '+')
		return ('+');
	else if (arg[i] == '=' && arg[i - 1] != '+')
		return ('=');
	return (0);
}
