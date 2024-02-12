/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerkul <alerkul@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:02:39 by alerkul           #+#    #+#             */
/*   Updated: 2024/02/07 14:34:44 by alerkul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

#include <unistd.h>
#include <fcntl.h>


char	*get_next_line(int fd);
char	*ft_strchr(char *s, int c);
char	*newstr(char new_str);
char	*get_str(char *new_str);
char	*read_line(int fd,char *new_str);

#endif
