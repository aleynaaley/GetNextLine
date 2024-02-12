#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

size_t	ft_strlen(const char *s);



int main()
{
 	// Bir dosya tanımlayıcısı değişkeni tanımlıyoruz.
	int fd;

 	// Bir dosya açıyoruz ve bu fonksiyon bize tanımlayıcı dönüyor.
 	// Genellikle 3 döner.
	fd = open("my_file.txt", O_RDWR | O_CREAT ,777);

	if (fd == -1) {
        perror("Dosya açma hatası");
        return 1;
    }
	// dosya içine  metin yazıyoruz
	const char *data_to_write = "Merhaba, dosyaya yazilan metin."; 
	
	ssize_t bytes_written = write(fd, data_to_write, strlen(data_to_write));

	//yazma hatası varmı kontrol ediyoruz
	if (bytes_written == -1) {
        perror("Dosyaya yazma hatası");
        close(fd);
        return 1;
    }

	// Dosyanın başlangıcına geri dön
    if (lseek(fd, 0, SEEK_SET) == -1)
    {
        perror("Dosya imleci konumlandırma hatası");
        close(fd);
        return 1;
    }
	
	// Dosyadan okuma yapmak için buffer boyutunu belirleyin
    size_t buffer_size = 100;
    char buffer[buffer_size];

    // Dosyadan buffer_size kadar veriyi okuyun
    ssize_t bytes_read = read(fd, buffer, buffer_size);

    if (bytes_read == -1)
    {
        perror("Dosyadan okuma hatası");
        close(fd);
        return 1;
    }

    // Okunan veriyi ekrana bastırın
    printf("%.*s", (int)bytes_read, buffer);
	 
	// Dosyayı kapat
    if (close(fd) == -1)
    {
        perror("Dosya kapatma hatası");
        return 1;
    }

	return (0);
}


size_t	ft_strlen(const char *s)
{
	size_t	length;

	length = 0;
	while (s[length] != '\0')
	{
		length++;
	}
	return (length);
}


//Bu kodda bir dosya açıyoruz içine bir metin yazıyor ve onun 100 karakter kadar okuyup yazdırıyor ve sonra dosyayı kapatıyoruz.


size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *left_str, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!left_str)
	{
		left_str = (char *)malloc(1 * sizeof(char));
		left_str[0] = '\0';
	}
	if (!left_str || !buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(left_str) + ft_strlen(buff)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (left_str)
		while (left_str[++i] != '\0')
			str[i] = left_str[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_strlen(left_str) + ft_strlen(buff)] = '\0';
	free(left_str);
	return (str);
}


