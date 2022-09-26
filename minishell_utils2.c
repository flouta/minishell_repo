/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flouta <flouta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 17:36:19 by flouta            #+#    #+#             */
/*   Updated: 2022/09/09 23:22:53 by flouta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	error_handling(char *msg)
{
	error_msg(msg, "\n");
}

int	_2d_len(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

int	key_len(char *var)
{
	int	i;

	i = 0;
	while (var[i] && var[i] != '=')
	{
		if ((var[i] == '+' && var[i + 1] == '=' ))
			break ;
		i++;
	}	
	return (i);
}

char	*get_key(char *var)
{
	char	*key;
	int		size_key;

	size_key = key_len(var);
	key = ft_substr(var, 0, size_key);
	return (key);
}

char	*get_value(char *var)
{
	char	*value;
	int		end;
	int		key_size;
	int		value_size;

	value_size = 0 ;
	end = ft_strlen(var);
	key_size = key_len(var);
	if (end == key_size)
		return (NULL);
	if (var[key_size] == '+' && var[key_size + 1] == '=')
		value_size = key_size + 2;
	else
		value_size = key_size + 1;
	value = ft_strdup(var + value_size);
	return (value);
}
