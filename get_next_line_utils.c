/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 12:45:21 by gde-sa            #+#    #+#             */
/*   Updated: 2023/08/26 18:04:59 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strchr(char *s)
{
	int	index;

	if (!s)
		return (-1);
	index = 0;
	while (s[index])
	{
		if (s[index] == '\n')
			return (index);
		index++;
	}
	return (-1);
}

size_t	strlen(const char *s)
{
	int		count;

	count = 0;
	while (*s)
	{
		count++;
		s++;
	}
	return (count);
}

char	*ft_strdup(const char *s)
{
	char	*str_dup;
	int		count_bytes;
	int		index;

	count_bytes = strlen(s);
	str_dup = malloc(count_bytes + 1 * sizeof(char));
	if (str_dup == NULL)
		return (NULL);
	str_dup[count_bytes] = '\0';
	index = 0;
	while (s[index])
	{
		str_dup[index] = s[index];
		index++;
	}
	return (str_dup);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_string;
	int		len_s1;
	int		len_s2;
	int		index;

	len_s1 = strlen(s1);
	len_s2 = strlen(s2);
	new_string = malloc((len_s1 + len_s2 + 1) * sizeof(char *));
	if (new_string == NULL)
		return (new_string);
	index = -1;
	while (s1[++index])
		new_string[index] = s1[index];
	index = -1;
	while (s2[++index])
		new_string[len_s1 + index] = s2[index];
	new_string[len_s1 + index] = '\0';
	return (new_string);
}
