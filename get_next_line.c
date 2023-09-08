/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 16:06:06 by gde-sa            #+#    #+#             */
/*   Updated: 2023/09/07 22:42:35 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*substring;
	size_t	len_s;
	size_t	i;

	if (s == NULL)
		return (NULL);
	len_s = ft_strlen(s);
	if (start >= len_s)
		return (ft_strdup(""));
	if (len >= len_s)
		len = len_s - start;
	substring = calloc(len + 2, sizeof(char *));
	if (substring == NULL)
		return (NULL);
	i = 0;
	while (s[i] && i <= len)
	{
		substring[i] = s[i + start];
		i++;
	}
	substring[i] = '\0';
	return (substring);
}

char	*ft_return_line(char *line, char **backup)
{
	int		index;
	char	*entire_line;

	index = 0;
	index = ft_source_n(line);
	entire_line = ft_substr(line, 0, index);
	if (index >= 0)
	{
		if (*backup != 0)
			free(*backup);
		(*backup) = ft_strdup(&line[index + 1]);
	}
	else
	{
		free(*backup);
		*backup = NULL;
	}
	return (entire_line);
}

char	*run_line(int fd, char **line)
{
	int			read_bytes;
	char		*buffer;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	read_bytes = 1;
	while (read_bytes > 0 && !(ft_source_n(*line) >= 0))
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
			return (clear_memory(NULL, buffer));
		buffer[read_bytes] = '\0';
		*line = ft_strjoin(*line, buffer);
	}
	if (*line[0] == '\0')
		return (clear_memory(*line, buffer));
	free(buffer);
	return (*line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*backup;

	if (fd < 0 || BUFFER_SIZE == 0)
		return (NULL);
	if (!backup)
		backup = "";
	line = ft_strdup(backup);
	if (line == NULL)
		return (clear_memory(line, NULL));
	line = run_line(fd, &line);
	if (line == NULL)
		return (clear_memory(line, NULL));
	else
	{
		line = ft_return_line(line, &backup);
		return (line);
	}
}

/*#include <stdio.h>

int	main(void)
{
	int		file;
	char	*result;
	int		i;

	file = open("arquivo.txt", O_RDONLY);
	i = 0;
	while (i < 15)
	{
		result = get_next_line(file);
		printf("%s", result);
		free(result);
		i++;
	}
}*/