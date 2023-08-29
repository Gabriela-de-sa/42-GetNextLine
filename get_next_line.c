/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 16:06:06 by gde-sa            #+#    #+#             */
/*   Updated: 2023/08/28 18:32:43 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_before_break(char *line)
{
	char	*str;
	int		index;
	char	*return_line;

	str = line;
	index = 0;
	while (str[index] && str[index] != '\n')
		index++;
	if (str[index] == '\0')
	{
		return_line = (char *) malloc(index + 1);
		if (return_line == NULL)
			return (NULL);
		return_line = ft_strncpy(return_line, str, index);
	}
	else
	{
		return_line = (char *) malloc(index + 1);
		if (return_line == NULL)
			return (NULL);
		return_line = ft_strncpy(return_line, str, index);
	}
	printf("%s", return_line);
	return (return_line);
}

/*char	*ft_after_break(char *str, int index, char *backup)
{
	int		len_str;
	char	*temp_backup;

	len_str = ft_strlen(str);
	temp_backup = backup;
	while (index <= len_str)
	{
		temp_backup[index] = str[index];
		index++;
	}
	printf("%s", temp_backup);
	return (temp_backup);
}*/

char	*ft_return_line(char *line, char *backup)
{
	char	*str;
	int		index;
	int		len_str;
	char	*entire_line;

	str = line;
	index = 0;
	while (str[index] && str[index] != '\n')
		index++;
	len_str = ft_strlen(str);
	if (len_str >= index)
	{
		while (index <= len_str)
		{
			backup[index] = str[index];
			index++;
		}
	}
	entire_line = ft_before_break(str);
	printf("%s", entire_line);
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
	buffer = malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	read_bytes = 1;
	while (read_bytes > 0 && !(ft_strchr(line) >= 0))
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes < 0)
			return (NULL);
		buffer[read_bytes] = '\0';
		line = ft_strjoin(line, buffer);
	}
	return (ft_return_line(line, backup));
}

int	main(void)
{
	int		file;
	int		i;

	file = open("arquivo.txt", O_RDONLY);
	i = 0;
	while (i < 10)
	{
		get_next_line(file);
		i++;
	}
}
