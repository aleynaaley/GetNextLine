/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerkul <alerkul@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:02:52 by alerkul           #+#    #+#             */
/*   Updated: 2024/02/07 20:48:55 by alerkul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_str(char *new_str)
{
	int		i;
	char	*str;

	i = 0;
	if (!new_str[i])
		return (NULL);
	while (new_str[i] && new_str[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (new_str[i] && new_str[i] != '\n')
	{
		str[i] = new_str[i];
		i++;
	}
	if (new_str[i] == '\n')
	{
		str[i] = new_str[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_new_str(char *new_str)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (new_str[i] && new_str[i] != '\n')
		i++;
	if (!new_str[i])
	{
		free(new_str);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(new_str) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (new_str[i])
		str[j++] = new_str[i++];
	str[j] = '\0';
	free(new_str);
	return (str);
}

char	*ft_strchr(char *s, int c)
{
	while (*s && *s != (char)c)
		s++;
	if (*s == (char)c)
		return ((char *)s);
	return (0);
}

size_t	ft_strlen(char *s)
{
	size_t	length;

	length = 0;
	while (s[length] != '\0')
	{
		length++;
	}
	return (length);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (0);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (0);
	while (s1[i] != '\0')
	{
		str[i] = ((unsigned char *)s1)[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		str[i + j] = ((unsigned char *)s2)[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}
