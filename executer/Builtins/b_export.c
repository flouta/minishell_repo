/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_export.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flouta <flouta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 15:20:25 by flouta            #+#    #+#             */
/*   Updated: 2022/09/01 17:28:13 by flouta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/minishell.h"

void	existing_var(t_env *var, t_env *found)
{
	if (var->flag == '+')
		append_value(found, var->value);
	if (var->flag == '=')
		overwrite_value(found, var->value);
}

void	add_export(char *arg)
{
	t_env	*var;
	t_env	*found;

	found = NULL;
	var = NULL;
	var = init_var(arg);
	found = list_srch(arg);
	if (found)
	{
		free(var->key);
		existing_var(var, found);
		free(var);
	}
	else
	{
		if (check_key(var->key) == -1)
		{
			free(var->key);
			free(var->value);
			free(var);
			g_var.exit_code = 1;
		}
		else
			add_first(var);
	}
}

void	run_export(char **arg)
{
	int		i;

	i = 0;
	while (arg[++i])
	{
		if (arg[i][0] == '\0' || is_empty(arg[i], ' ') == 1)
		{
			error_msg(arg[i], ": not a valid identifier\n");
			g_var.exit_code = 1;
		}
		else
			add_export(arg[i]);
	}
}

void	b_export(char **arg)
{
	if (arg[1] == NULL)
		display_export();
	else
		run_export(arg);
}
