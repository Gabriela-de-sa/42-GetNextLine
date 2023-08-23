/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriela <gabriela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 11:25:20 by gde-sa            #+#    #+#             */
/*   Updated: 2023/08/23 19:57:21 by gabriela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 7

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_line
{
	void			*content;
	struct s_line	*next;
}	t_line;


char			*get_next_line(int fd);
char			*ft_strchr(char *s, char c);
size_t			ft_strlen(const char *x);
char			*run_line(char *line);



#endif