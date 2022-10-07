/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_files2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flouta <flouta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 23:33:21 by flouta            #+#    #+#             */
/*   Updated: 2022/09/09 23:33:58 by flouta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/minishell.h"
int	*in_file(t_rdr *head, int *in_out)
{
	if (in_out[0] != 0)
		close(in_out[0]);
	in_out[0] = open(head->content, O_RDONLY);
	if (in_out[0] < 0)
	{
		perror("FILE");
		in_out[2] = -1;
	}
	return (in_out);
}
