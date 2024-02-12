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

// buffer size kadar satır üzerinde okuma yapayıyro ve /n 
char	*read_line(int fd, char *new_str)
{
	char	*ytr;
	int		byte_count;
	
	ytr = malloc((BUFFER_SİZE + 1)* sizeof(char));
	if(!ytr)
		return (NULL);
	byte_count = 1;       //okunan byte sayısı
	while(!ft_strchr(new_str, '\n') && byte_count != 0)
	{
		byte_count = read(fd, ytr, BUFFER_SIZE);
		if(byte_count == -1)
		{
			free(ytr);
			return (NULL);
		}
		ytr[byte_count] = '\0';
		new_str = ft_strjoin(new_str, ytr);
	}
	free(ytr);
	return(new_str);	
}


// bu fonksiyonda newstr de ki alt satırda okuduğu fazlalığı çıkarıp str ye ilk satırı atar
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


char	*newstr(char *new_str)
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
