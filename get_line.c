/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flouta <flouta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 16:01:37 by flouta            #+#    #+#             */
/*   Updated: 2022/09/09 23:24:07 by flouta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_srchr1(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*line_join(char *line, char c)
{
	char	*new;
	int		i;

	i = 0;
	while (line && line[i])
		i++;
	new = malloc(sizeof(char) * (i + 2));
	if (!new)
	{
		free(line);
		return (NULL);
	}
	i = 0;
	while (line && line[i])
	{
		new[i] = line[i];
		i++;
	}
	new[i++] = c;
	new[i] = 0;
	free(line);
	return (new);
}

char	*get_line2(int fd)
{
	char	*line;
	char	c;
	int		count;

	line = NULL;
	write(1, "> ", 2);
	while (!check_srchr1(line))
	{
		count = read(fd, &c, 1);
		if (count == -1)
			return (NULL);
		if (count)
			line = line_join(line, c);
		if (!line)
			return (NULL);
	}
	return (line);
}
