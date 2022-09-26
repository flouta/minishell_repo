/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_pwd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flouta <flouta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 15:22:14 by flouta            #+#    #+#             */
/*   Updated: 2022/08/29 15:22:30 by flouta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	b_pwd(void)
{
	char	*path;

	path = NULL;
	path = getcwd(path, PATH_MAX);
	if (path == NULL)
	{
		perror("PWD");
		g_var.exit_code = 1;
		return ;
	}
	printf("%s\n", path);
	free(path);
}
