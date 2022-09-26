/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flouta <flouta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 16:08:50 by flouta            #+#    #+#             */
/*   Updated: 2022/09/01 19:29:52 by flouta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	display_env(void)
{
	t_env	*tmp;

	tmp = g_var.env;
	while (tmp)
	{
		printf("%s=%s\n", tmp->key, tmp->value);
		tmp = tmp->next;
	}
}

t_env	*f_oldpwd(void)
{
	t_env	*head;
	t_env	*srch;

	head = g_var.env;
	srch = list_srch("OLDPWD");
	if (srch != NULL)
	{
		free(srch->value);
		srch->value = NULL;
	}
	else
		add_env_var("OLDPWD", head);
	return (head);
}

t_env	*init_env(char **env)
{
	int		list_size;
	t_env	*head;
	int		i;

	head = NULL;
	list_size = _2d_len(env);
	i = 0;
	while (i < list_size)
	{
		head = add_env_var(env[i], head);
		i++;
	}
	return (head);
}

t_env	*add_env_var(char *env, t_env *head)
{
	t_env	*curr;
	t_env	*tmp;

	tmp = NULL;
	curr = (t_env *)malloc(sizeof(t_env));
	if (!curr)
		error_handling("HEAP OVERFLOW");
	curr->key = get_key(env);
	curr->flag = get_flag(env);
	curr->value = get_value(env);
	curr->next = NULL;
	if (head == NULL)
		head = curr;
	else
	{
		tmp = head;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = curr;
	}
	return (head);
}
