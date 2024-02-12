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

#include "get_next_line.h"

char	*read_line(int fd, char *new_str)
{
	char	*ytr;
	int		byte_count;

	ytr = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!ytr)
		return (NULL);
	byte_count = 1;
	while (!ft_strchr(new_str, '\n') && byte_count != 0)
	{
		byte_count = read(fd, ytr, BUFFER_SIZE);
		if (byte_count == -1)
		{
			free(ytr);
			return (NULL);
		}
		ytr[byte_count] = '\0';
		new_str = ft_strjoin(new_str, ytr);
	}
	free(ytr);
	return (new_str);
}

char	*get_next_line(int fd)
{
	char		*str;
	static char	*new_str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	new_str = read_line(fd, new_str);
	if (!new_str)
		return (NULL);
	str = get_str(new_str);
	new_str = ft_new_str(new_str);
	return (str);
}
