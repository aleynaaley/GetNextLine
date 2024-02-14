/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerkul <alerkul@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:02:39 by alerkul           #+#    #+#             */
/*   Updated: 2024/02/14 09:43:49 by alerkul          ###   ########.fr       */
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

size_t	ft_strlen(char *str);
int		newline_count(char *str);
char	*ft_strjoin(char *new_str, char *chr);
char	*ft_strchr(char *str, int c);
char	*get_line_a(char *str);
char	*new_line(char *str);
char	*read_line(int fd, char *str);
char	*get_next_line(int fd);
#endif 
