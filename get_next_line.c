/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 16:06:06 by gde-sa            #+#    #+#             */
/*   Updated: 2023/09/08 17:45:03 by gabriela         ###   ########.fr       */
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

char	*ft_return_line(char **backup)
{
	int		index;
	char	*entire_line;
	char	*temp_backup;

	index = 0;
	index = ft_source_n(*backup);
	entire_line = ft_substr(*backup, 0, index);
	if (index < 0)
	{
		free(*backup);
		*backup = NULL;
	}
	if (index >= 0)
	{
		temp_backup = ft_strdup(*backup + index + 1);
		free(*backup);
		*backup = temp_backup;
	}
	return (entire_line);
}

char	*run_line(int fd, char **backup)
{
	int			read_bytes;
	char		*buffer;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	read_bytes = 1;
	while (read_bytes > 0 && !(ft_source_n(*backup) >= 0))
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
			return (clear_memory(NULL, buffer));
		buffer[read_bytes] = '\0';
		if (!(*backup))
			*backup = ft_strdup(buffer);
		else
			*backup = ft_strjoin(*backup, buffer);
	}
	if (*backup[0] == '\0')
		return (clear_memory(*backup, buffer));
	free(buffer);
	return (*backup);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*backup;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	backup = run_line(fd, &backup);
	if (backup == NULL)
		return (NULL);
	else
	{
		line = ft_return_line(&backup);
		return (line);
	}
}

#include <stdio.h>

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
}
