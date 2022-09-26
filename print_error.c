/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flouta <flouta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 17:39:00 by ridrissi          #+#    #+#             */
/*   Updated: 2022/09/09 23:21:43 by flouta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	print_error(void)
{
	printf("\033[0;31m");
	printf("SYNTAX ERROR\n");
	printf("\033[0m");
	return (0);
}
