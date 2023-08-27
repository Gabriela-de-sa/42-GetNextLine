/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 16:06:06 by gde-sa            #+#    #+#             */
/*   Updated: 2023/08/26 18:20:24 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*return_line(char *line, char *backup)
{
	
}

char	*get_next_line(int fd)
{
	char		*line;
	int			read_bytes;
	char		*buffer;
	static char	*backup;

	if (fd < 0 || BUFFER_SIZE == 0)
		return (NULL);
	if (!backup)
		backup = ft_strdup("");
	line = ft_strdup(backup);
	buffer = malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	read_bytes = 1;
	while (read_bytes > 0 && !(ft_strchr(line) > 0))
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes < 0)
			return (NULL);
		buffer[read_bytes] = '\0';
		line = ft_strjoin(line, buffer);
	}
	printf("%s", line);
	return (0);
}

int	main(void)
{
	int		file;
	int		i;

	file = open("arquivo.txt", O_RDONLY);
	i = 0;
	while (i < 1)
	{
		get_next_line(file);
		i++;
	}
}
