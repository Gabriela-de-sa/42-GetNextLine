/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arquivo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-sa <gde-sa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 13:03:13 by gde-sa            #+#    #+#             */
/*   Updated: 2023/08/19 14:56:47 by gde-sa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int	main(void)
{
	int		file;
	ssize_t	ler;
	char	buffer[100];

	file = open("arquivo.txt", O_RDONLY);
	if (file < 0)
		printf("erro");
	else
		printf("arquivo aberto - fd %i", file);
	ler = read(file, buffer, 100);
	printf("\n%s", buffer);
}

/*
read
	- fd que é usado quando é aberto 
	- buffer é determinado pela quantidade que eu passo para o terceiro
	argumento
	- tanto de bytes que vai ser lido do arquivo e o que determina o tamanho
	do buffer
*/