/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_env.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flouta <flouta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 15:18:17 by flouta            #+#    #+#             */
/*   Updated: 2022/08/29 18:44:29 by flouta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	b_env(char **arg)
{
	t_env	*var;

	var = g_var.env;
	if (list_srch("PATH") == NULL || arg[1])
	{
		error_msg("env", ": No such file or directory\n");
		g_var.exit_code = 127;
		return ;
	}
	while (var)
	{
		if (var->key != NULL && var->value != NULL)
			printf("%s%s=%s%s\n", var->key, "\x1B[32m", "\x1B[0m", var->value);
		var = var->next;
	}
}
