/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_arg_arr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridrissi <ridrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 18:31:34 by ridrissi          #+#    #+#             */
/*   Updated: 2022/09/09 18:57:49 by ridrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_arg_arr(char **arg_arr)
{
	int	i;

	i = 0;
	while (arg_arr && arg_arr[i] != 0)
		free(arg_arr[i++]);
	free(arg_arr);
}
