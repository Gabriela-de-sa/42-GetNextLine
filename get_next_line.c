/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-sa <gde-sa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 16:06:06 by gde-sa            #+#    #+#             */
/*   Updated: 2023/08/21 17:59:08 by gde-sa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

// verifica a qantidade de palavras para o malloc
// lista encadeada
// retorna a lista
static char	*line_find(char buffer)
{
	printf("%c", buffer);
}

// percorrer a sring ate o \n dependendo do buffer _size
static char	run_line(int fd)
{
	static char	buffer;

	read(fd, buffer, BUFFER_SIZE);
	if (ft_strchr(buffer, '\n') != NULL)
		line_find(buffer);
	
}

char	*get_next_line(int fd)
{
	if (fd < 0 || BUFFER_SIZE == 0)
		return (NULL);
	run_line(fd);
}


int	main(void)
{
	int		file;

	file = open("arquivo.txt", O_RDONLY);
	get_next_line(file);
}

