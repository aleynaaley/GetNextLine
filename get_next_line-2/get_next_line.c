/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerkul <alerkul@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:02:23 by alerkul           #+#    #+#             */
/*   Updated: 2024/02/12 22:47:13 by alerkul          ###   ########.fr       */
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

char	*get_str(char *neww_str)
{
	char	*str;
	int		newline;
	int		i;

	if (!neww_str || neww_str[0] == '\0')
		return (NULL);
	i = 0;
	newline = newline_count(neww_str);
	str = malloc(sizeof(char) * (newline + 2));
	if (!str)
		return (NULL);
	while (neww_str[i] != '\0' && neww_str[i] != '\n')
	{
		str[i] = neww_str[i];
		i++;
	}
	if (neww_str[i] == '\n')
	{
		str[i] = neww_str[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*new_str;
	char		*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	new_str = read_line(fd, new_str);
	if (!new_str)
		return (NULL);
	str = get_str(new_str);
	new_str = neww_str(new_str);
	return (str);
}
