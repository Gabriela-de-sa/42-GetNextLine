/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 11:25:20 by gde-sa            #+#    #+#             */
/*   Updated: 2023/08/26 00:11:55 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 7

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

char			*get_next_line(int fd);
int				ft_strchr(char *s);
size_t			ft_strlen(const char *x);
char			*ft_strdup(const char *s);
char			*ft_strjoin(char const *s1, char const *s2);

#endif