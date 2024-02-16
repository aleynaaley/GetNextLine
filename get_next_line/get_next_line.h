
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
