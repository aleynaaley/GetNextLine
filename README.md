# Dosya İşlemleri
Dosya işlemleri, bir bilgisayar programının dosyalarla etkileşimde bulunmasını sağlayan işlemleri ifade eder. Bu işlemler, dosyaları açma, okuma, yazma, kapatma ve dosya üzerinde diğer çeşitli operasyonları içerir. 

# File Discriptor
Dosya tanımlayıcıları (File Descriptor) sistemdeki bir dosyanın bellekteki adresini belirtir. Dosya tanımlayıcısı (File Descriptor) bir dosyaya erişim sağlayan bir tam sayıdır. Bu sayı genellikle 3 olur. Bunun sebebi ‘Dosya tanımlayıcısı tablosu’ (file descriptor table) dediğimiz şeydir. Bu tablo :

`0 -> Standart Input.`

`1 -> Standart Output.`

`2 -> Standart Error.`

Tablomuz bu şekilde başladığı için sıradaki ilk müsait tanımlayıcı 3'dür. Bu sebeple biz bir dosyayı açtığımızda genellikle tanımlayıcımız 3 olur.

⚡Kısacası dosya tanımlayıcıları sistemdeki bir dosyaya erişmek için kullanılır ve bu erişim, sistemdeki dosyalarda okuma, yazma ve değiştirme işlemlerini gerçekleştirmek için gereklidir.

örnekk 
 ```bash
  
   
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
  // Bir dosya tanımlayıcısı değişkeni tanımlıyoruz.
  int fd;

  // Bir dosya açıyoruz ve bu fonksiyon bize tanımlayıcı dönüyor.
  // Genellikle 3 döner.
  fd = open("my_file.txt", O_RDONLY);
  
  // Açılan dosyaya erişim sağlıyoruz.
  char buffer[100];
  read(fd, buffer, 100);

  // Okuduğumuz veriyi ekrana bastırabiliriz.
  printf("%s", buffer);

  // Dosyamızı kapatıyoruz.
  close(fd);
  
  return (0);
}
```


