/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_utils3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flouta <flouta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 17:27:10 by flouta            #+#    #+#             */
/*   Updated: 2022/09/01 17:28:00 by flouta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*init_var(char *arg)
{
	t_env	*var;

	var = (t_env *)malloc(sizeof(t_env));
	if (!var)
		error_handling("OVERFLOW\n");
	var->key = get_key(arg);
	var->value = get_value(arg);
	var->flag = get_flag(arg);
	var->next = NULL;
	return (var);
}

void	add_first(t_env *var)
{
	var->next = g_var.env;
	g_var.env = var;
}

t_env	*copy_list(t_env *env)
{
	t_env	*new_node;

	new_node = NULL;
	if (env == NULL)
		return (NULL);
	else
	{
		new_node = (t_env *)malloc(sizeof(t_env));
		if (!new_node)
			error_handling("OVERFLOW\n");
		new_node->key = env->key;
		new_node->value = env->value;
		new_node->flag = 0;
		new_node->next = copy_list(env->next);
		return (new_node);
	}
}

int	max_len(char *s1, char *s2)
{
	int	l1;
	int	l2;

	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	if (l1 > l2)
		return (l1);
	else
		return (l2);
}

t_env	*sort_list(t_env *env_dup)
{
	t_env	*head;
	char	*key;
	char	*value;

	head = env_dup;
	key = NULL;
	value = NULL;
	while (head->next)
	{
		if (ft_strncmp(head->key, head->next->key) > 0)
		{
			key = head->key;
			head->key = head->next->key;
			head->next->key = key;
			value = head->value;
			head->value = head->next->value;
			head->next->value = value;
			head = env_dup;
		}
		else
			head = head->next;
	}
	return (env_dup);
}
