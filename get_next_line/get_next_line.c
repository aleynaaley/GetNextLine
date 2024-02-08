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


char	*read_line(int fd, char *stack)
{
	char	*buffer;
	int		read_byte;

	read_byte = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (!ft_strchr(stack, '\n') && read_byte != 0)
	{
		read_byte = read(fd, buffer, BUFFER_SIZE);
		if (read_byte == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[read_byte] = '\0';
		stack = ft_strjoin(stack, buffer);
	}
	free(buffer);
	return (stack);
}


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

