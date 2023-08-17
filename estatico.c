/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-sa <gde-sa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 11:21:04 by gde-sa            #+#    #+#             */
/*   Updated: 2023/08/17 15:50:37 by gde-sa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void funcao1()
{
	int	j = 0;
	printf("%i\n", j);
	j++;
}

void funcao2()
{
	static int	x;
//	x = 0;
	printf("%i\n", x);
	x++;
}

int main(void)
{
	int	a;
	int	b;

	printf("funcao 1\n");
	for (a = 0; a < 10; a++)
	{
		funcao1();
	}

	printf("\n\nfuncao 2\n");
	b = 0;
	while (b < 10)
	{
		funcao2();
		b++;
	}	
}