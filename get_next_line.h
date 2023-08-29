/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 11:25:20 by gde-sa            #+#    #+#             */
/*   Updated: 2023/08/28 18:27:03 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# define BUFFER_SIZE 8

char			*get_next_line(int fd);
int				ft_strchr(char *s);
size_t			ft_strlen(char *x);
char			*ft_strdup(char *s);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_return_line(char *line, char *backup);
char			*ft_strncpy(char *dest, char *src, size_t n);
char			*ft_before_break(char *line);
char			*ft_strncpy(char *dest, char *src, size_t n);

#endif