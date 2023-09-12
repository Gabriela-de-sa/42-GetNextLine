/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-sa <gde-sa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 16:06:06 by gde-sa            #+#    #+#             */
/*   Updated: 2023/09/12 13:09:07 by gde-sa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*clear_memory(char *s1, char *s2)
{
	if (s1 != NULL)
		free(s1);
	if (s2 != NULL)
	{
		free(s2);
		s2 = NULL;
	}
	return (NULL);
}

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
	substring = ft_calloc(len + 2, sizeof(char *));
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
		temp_backup = ft_strdup(&(*backup)[index + 1]);
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
			return (clear_memory(*backup, buffer));
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
	static char	*backup[1024];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	backup[fd] = run_line(fd, &backup[fd]);
	if (backup[fd] == NULL)
		return (NULL);
	else
	{
		line = ft_return_line(&backup[fd]);
		return (line);
	}
}
