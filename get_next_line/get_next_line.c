/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerkul <alerkul@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:02:23 by alerkul           #+#    #+#             */
/*   Updated: 2024/02/07 21:21:31 by alerkul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// read , malloc, free kullanabilirsin
//fd nin işaret ettiği metin dosyasının her seferinde sadece tek satır okuyacak 


#include get_next_line.h


char *get_next_line(int fd){
    static char	*stack;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stack = read_line(fd, stack);
	if (!stack)
		return (NULL);
	line = get_line(stack);
	stack = new_line(stack);
	return (line);
}

