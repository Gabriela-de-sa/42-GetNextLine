/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 16:06:06 by gde-sa            #+#    #+#             */
/*   Updated: 2023/08/23 19:56:12 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char	*find_break(int fd, char *backup)
{
	char		buffer;
	int			read_bytes;

	read_bytes = 1;
	while (read_bytes > 0 && !ft_strchr(buffer, '\n'))
	{
		read(fd, buffer, BUFFER_SIZE);
	}
	return (backup);
}

char	*get_next_line(int fd)
{
	char	*backup;
	char	*line;

	if (fd < 0 || BUFFER_SIZE == 0)
		return (NULL);
	backup = find_break(fd, backup);
}

int	main(void)
{
	int		file;
	int		i;

	file = open("arquivo.txt", O_RDONLY);
	get_next_line(file);
}
