/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 12:45:21 by gde-sa            #+#    #+#             */
/*   Updated: 2023/08/23 19:03:36 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_strchr(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

size_t	ft_strlen(const char *x)
{
	size_t	count;

	count = 0;
	while (*x)
	{
		count++;
		x++;
	}
	return (count);
}

char	*run_line(char *line)
{
	int		index;
	char	*line_break;

	printf("%s", line);
	index = 0;
	while (line[index] != '\n')
		index++;
	line_break = malloc(index + 1 * sizeof(char *));
	if (line_break == NULL)
		return (NULL);
	index = -1;
	while (line[index++] != '\n')
		line_break[index] = line[index];
	line_break[index] = '\n';
	printf("%s", line_break);
	return (line_break);
}
