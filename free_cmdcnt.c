/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_cmdcnt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridrissi <ridrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 18:32:49 by ridrissi          #+#    #+#             */
/*   Updated: 2022/09/09 18:57:40 by ridrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_cmdcnt(t_cmd *comd)
{
	if (comd->cmd && comd->cmd[0] != '\0')
		free(comd->cmd);
	free_arg_arr(comd->arg_arr);
	free_args(comd->args);
	free_rdr(comd->rdr);
	free(comd->in_out);
}
