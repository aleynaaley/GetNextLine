                                                                  
#include "get_next_line.h"

char	*read_line(int fd, char *str)
{
	char	*buffer;
	int		byte;

	byte = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (!ft_strchr(str, '\n') && byte != 0)
	{
		byte = read(fd, buffer, BUFFER_SIZE);
		if (byte == -1)
			return (free(buffer), free(str), NULL);
		buffer[byte] = '\0';
		str = ft_strjoin(str, buffer);
		if (!str)
			return (free(buffer), NULL);
	}
	return (free(buffer), str);
}

char	*new_line(char *str)
{
	int		i;
	int		s;
	char	*nbr;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	pı≥o
	if (str[i] == '\0')
	{
		free(str);
		return (NULL);
	}
	nbr = malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!nbr)
		return (NULL);
	i++;
	s = 0;
	while (str[i])
		nbr[s++] = str[i++];
	nbr[s] = '\0';
	free(str);
	return (nbr);
}

char	*get_line_a(char *str)
{
	char	*vrb;
	int		newline;
	int		i;

	if (!str || str[0] == '\0')
		return (NULL);
	i = 0;
	newline = newline_count(str);
	vrb = malloc(sizeof(char) * (newline + 2));
	if (!vrb)
		return (NULL);
	while (str[i] != '\0' && str[i] != '\n')
	{
		vrb[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		vrb[i] = str[i];
		i++;
	}
	vrb[i] = '\0';
	return (vrb);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = read_line(fd, str);
	if (!str)
		return (NULL);
	line = get_line_a(str);
	str = new_line(str);
	return (line);
}
