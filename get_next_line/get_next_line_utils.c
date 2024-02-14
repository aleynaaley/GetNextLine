/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerkul <alerkul@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:02:52 by alerkul           #+#    #+#             */
/*   Updated: 2024/02/14 08:52:26 by alerkul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

int	newline_count(char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\n' && str[count] != '\0')
		count++;
	return (count);
}

char	*ft_strjoin(char *new_str, char *chr)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!new_str)
	{
		new_str = (char *)malloc(1 * sizeof(char));
		new_str[0] = '\0';
	}
	if (!new_str || !chr)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(new_str) + ft_strlen(chr)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (new_str)
		while (new_str[++i] != '\0')
			str[i] = new_str[i];
	while (chr[j] != '\0')
		str[i++] = chr[j++];
	str[ft_strlen(new_str) + ft_strlen(chr)] = '\0';
	free(new_str);
	return (str);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}
