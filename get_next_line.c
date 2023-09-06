/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-sa <gde-sa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 16:06:06 by gde-sa            #+#    #+#             */
/*   Updated: 2023/09/06 18:18:45 by gde-sa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

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
	substring = (char *) malloc(len + 2);
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
	if (index >= 0)
	{
		entire_line = ft_substr(*backup, 0, index);
		temp_backup = *backup;
		if (*backup[0] != '\0')
			free(*backup);
		(*backup) = ft_strdup(&temp_backup[index + 1]);
	}
	else
	{
		entire_line = NULL;
		return (*backup);
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
		if (*backup == NULL)
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
	static char	*backup;
	char		*line;

	if (fd < 0 || BUFFER_SIZE == 0)
		return (NULL);
	if (!backup)
		backup = NULL;
	run_line(fd, &backup);
	if (backup == NULL)
		return (NULL);
	else
	{
		line = ft_return_line(&backup);
		return (line);
	}
}

int	main(void)
{
	int		file;
	int		i;

	file = open("arquivo.txt", O_RDONLY);
	i = 0;
	while (i < 15)
	{
		char *result;
	
		result = get_next_line(file);
		printf("%s", result);
		if (result == NULL)
			break ;
		free(result);
		i++;
	}
}
