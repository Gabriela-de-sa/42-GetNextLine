/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-sa <gde-sa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 11:25:20 by gde-sa            #+#    #+#             */
/*   Updated: 2023/08/29 18:09:47 by gde-sa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000
# endif

char			*get_next_line(int fd);
int				ft_strchr(char *s);
size_t			ft_strlen(char *x);
char			*ft_strdup(char *s);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_return_line(char *line, char **backup);
char			*ft_strncpy(char *dest, char *src, size_t n);
char			*ft_strncpy(char *dest, char *src, size_t n);
char			*ft_substr(char *s, unsigned int start, size_t len);


#endif