/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_arg_arr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridrissi <ridrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 18:24:48 by ridrissi          #+#    #+#             */
/*   Updated: 2022/09/09 18:59:46 by ridrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**create_arg_arr(t_args *args, char *cmd)
{
	char	**str;
	int		i;
	int		cmdlen;

	if (!cmd && !args)
		return (0);
	str = 0;
	i = 0;
	cmdlen = 0;
	if (cmd)
		cmdlen = 1;
	str = (char **) malloc(sizeof(char *) * (listlen(args) + cmdlen + 1));
	str[listlen(args) + cmdlen] = 0;
	add_cmd_str(str, cmd);
	if (cmd)
		i = 1;
	add_args_str(str, args, i);
	return (str);
}
