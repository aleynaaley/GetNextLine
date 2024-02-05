# Dosya İşlemleri
Dosya işlemleri, bir bilgisayar programının dosyalarla etkileşimde bulunmasını sağlayan işlemleri ifade eder. Bu işlemler, dosyaları açma, okuma, yazma, kapatma ve dosya üzerinde diğer çeşitli operasyonları içerir. 

# File Discriptor
Dosya tanımlayıcıları (File Descriptor) sistemdeki bir dosyanın bellekteki adresini belirtir. Dosya tanımlayıcısı (File Descriptor) bir dosyaya erişim sağlayan bir tam sayıdır. Bu sayı genellikle 3 olur. Bunun sebebi ‘Dosya tanımlayıcısı tablosu’ (file descriptor table) dediğimiz şeydir. Bu tablo :

`0 -> Standart Input.`

`1 -> Standart Output.`

`2 -> Standart Error.`

Tablomuz bu şekilde başladığı için sıradaki ilk müsait tanımlayıcı 3'dür. Bu sebeple biz bir dosyayı açtığımızda genellikle tanımlayıcımız 3 olur.

⚡Kısacası dosya tanımlayıcıları sistemdeki bir dosyaya erişmek için kullanılır ve bu erişim, sistemdeki dosyalarda okuma, yazma ve değiştirme işlemlerini gerçekleştirmek için gereklidir.

 ```bash

int fd = open ( "example.txt" , O_RDONLY); //
char buffer[ 256 ] dosyasını açın ; 
oku (fd, arabellek, 256 ); // 256 byte'ı oku 
kapat (fd); // Dosyayı kapat

```
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


notlar 
-- dosya tanımlayıcısı ile inodeler arasındaki fark----
Dosya Tanımlayıcıları, dosyalarla etkileşim için geçici, çalışma zamanı geçişleriniz gibidir; Inode'lar ise tüm önemli ayrıntıları tutan kalıcı sahne arkası kimlikleridir.

İlişki
İşte nasıl etkileşimde bulundukları:

Dosya Açma : Bir dosyayı açtığınızda, işletim sistemi dosyanın meta verilerini almak için Inode'u arar ve ardından gelecekteki işlemler için bir Dosya Tanımlayıcı sağlar.
Okuma/Yazma : Bir FD kullanarak okuduğunuzda veya yazdığınızda, işletim sistemi, diskteki verilerin nerede okunacağını/yazılacağını bulmak için Inode'a başvurur.
Çoklu Erişim : Farklı işlemler aynı dosyayı açtığında veya bir dosyanın birden fazla sabit bağlantısı olduğunda birden fazla FD aynı Inode'a işaret edebilir.



...................................................
 dosya tanımlayıcıları genellikle bir tam sayı değeri olarak temsil edilir ve genellikle int veri tipi kullanılır. İşletim sistemi, bir dosya açıldığında, o dosyayı temsil etmek için benzersiz bir tam sayı değeri atar. Bu değer, programın o dosyayı daha sonra okuması veya yazması için bir “tanımlayıcı” veya “işaretçi” olarak kullanılır.

Örneğin, Unix ve Unix-benzeri işletim sistemlerinde (Linux, BSD, macOS vb.), open sistem çağrısı bir dosyayı açar ve bir dosya tanımlayıcısı döndürür. Bu dosya tanımlayıcısı, read, write, close gibi diğer sistem çağrılarında kullanılır.

Bununla birlikte, dosya tanımlayıcıları sadece dosyalar için değil, aynı zamanda ağ soketleri, cihazlar, hatta bazen işlemler ve hafıza alanları gibi diğer sistem kaynakları için de kullanılır. Bu, işletim sisteminin bu kaynakları birleşik bir şekilde yönetmesini sağlar. Bu nedenle, dosya tanımlayıcıları genellikle “kaynak tanımlayıcıları” olarak da adlandırılır
