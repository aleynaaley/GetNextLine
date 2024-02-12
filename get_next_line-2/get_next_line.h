/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerkul <alerkul@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:02:39 by alerkul           #+#    #+#             */
/*   Updated: 2024/02/12 22:39:20 by alerkul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

int		newline_count(char *str2);
size_t	ft_strlen(char *s);
char	*get_next_line(int fd);
char	*read_line(int fd, char *new_str);
char	*get_str(char *neww_str);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *left_str, char *buff);
char	*neww_str(char *new_str);
#endif 
