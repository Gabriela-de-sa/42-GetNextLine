/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-sa <gde-sa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 16:06:06 by gde-sa            #+#    #+#             */
/*   Updated: 2023/08/29 18:10:16 by gde-sa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*substring;
	size_t	len_s;
	size_t	i;

	len_s = ft_strlen(s);
	if (start >= len_s)
		return (ft_strdup(""));
	if (s == 0)
		return (NULL);
	if (len >= len_s)
		len = len_s - start;
	substring = (char *) malloc(len + 1);
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
	index = ft_strchr(line);
	entire_line = ft_substr(line, 0, index);
	if (index >= 0)
		(*backup) = ft_strdup(&line[index + 1]);
	else
	{
		free(*backup);
		*backup = NULL;
	}
	return (entire_line);
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
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	read_bytes = 1;
	while (read_bytes > 0 && !(ft_strchr(line) >= 0))
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
			return (NULL);
		buffer[read_bytes] = '\0';
		line = ft_strjoin(line, buffer);
	}
	if (line[0] == '\0')
		return (NULL);
	return (ft_return_line(line, &backup));
}

/*int	main(void)
{
	int		file;
	int		i;

	file = open("arquivo.txt", O_RDONLY);
	i = 0;
	while (i < 15)
	{
		printf("%s", get_next_line(file));
		i++;
	}
}*/
