/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 11:25:20 by gde-sa            #+#    #+#             */
/*   Updated: 2023/09/10 19:11:59 by gabriela         ###   ########.fr       */
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
int				ft_source_n(char *s);
size_t			ft_strlen(char *x);
char			*ft_strdup(char *s);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_return_line(char **backup);
char			*ft_substr(char *s, unsigned int start, size_t len);
char			*run_line(int fd, char **backup);
void			*clear_memory(char *s1, char *s2);
void			*ft_calloc(size_t nitems, size_t size);

#endif