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
    size_t buffer_size = 5;
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