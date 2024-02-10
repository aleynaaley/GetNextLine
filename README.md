# Dosya Nedir?

Dosya üst bilgileri genellikle dosyanın kendisi içinde değil, işletim sistemi tarafından yönetilen bir dosya sistemi içinde tutulur. Bu bilgiler genellikle `meta veri` olarak adlandırılır ve dosya adı, oluşturma tarihi, son değiştirilme tarihi, dosya boyutu ve sahibi gibi bilgileri içerir.

Bir dosya sistemi, bir işletim sistemi tarafından kullanılan bir yapıdır ve sabit disk sürücü, katı hal sürücüsü (SSD) veya USB flash sürücü gibi bir veri saklama cihazlarında dosyaları düzenlemek ve yönetmek için kullanılır

Dosya sistemi, verilerin veri saklama cihazında nasıl saklandığını, düzenlendiğini ve verilere nasıl erişildiğini tanımlar.

İşletim sistemi, bilgisayarın bellek, işlemci, dosya sistemleri, cihaz sürücüleri ve ağ bağlantıları gibi kaynaklara erişimi düzenler ve kullanıcıların bu kaynakları etkili bir şekilde kullanabilmesini sağlar. İşletim sistemi genellikle çekirdek (kernel) ve kullanıcı arayüzü (shell) olmak üzere iki temel bileşenden oluşur

Çekirdek, işletim sisteminin temel parçasıdır ve en düşük seviyede donanım kaynaklarını yönetir. Bellek yönetimi, işlem yönetimi, dosya sistemleri, sürücüler ve ağ bağlantıları gibi temel işlevleri yerine getirir. Çekirdek, doğrudan donanım ile iletişim kurar ve uygulamaların bu kaynaklara erişimini sağlar

Özetle, bir dosya sistemi, bir işletim sistemi tarafından yönetilen ve dosyaların bir depolama cihazında nasıl düzenlendiğini ve yönetildiğini belirleyen bir yapıdır

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

open(): bir dosyayı açmak için kullanılır ve bir dosya tanımlayıcısı (file descriptor) döndürür.Eğer bir hata oluşursa, -1 değerini döndürür. 
 ```bash
int open(const char *filename, int flags, mode_t mode);
 ```

`open` fonksiyonunda kullanılan flagler aşağıdaki gibidir1:

- `O_RDONLY:` Dosyayı sadece okuma modunda açar1.
- `O_WRONLY:` Dosyayı sadece yazma modunda açar1.
- `O_RDWR: `Dosyayı hem okuma hem yazma modunda açar1.
- `O_APPEND:` Dosyayı eklemek için açar1. Bu bayrak belirtildiğinde, tüm yazma işlemleri dosyanın sonuna yapılır1.
- `O_CREAT:` Dosyayı oluşturmak için açar1. Bu bayrak belirtildiğinde ve dosya mevcut değilse, open fonksiyonu dosyayı oluşturur1.
- `O_TRUNC:` Dosyayı sıfırlamak için açar1. Bu bayrak belirtildiğinde ve dosya mevcut ise, open fonksiyonu dosyanın boyutunu sıfırlar1.
- `O_EXCL:` Dosyayı özel olarak açar1. Bu bayrak, O_CREAT bayrağı ile birlikte kullanıldığında, dosya zaten varsa open fonksiyonu hata döndürür1.

close():  Açık dosya tanımlayıcılarını kapatır (soketler dahil). Bu, işletim sistemine, o dosya tanımlayıcısı veya soket için ayrılan kaynakları serbest bırakmasını söyler.
 ```bash
int close(int fd);
 ```
Fonksiyon başarılı olduğunda 0, hata durumunda -1 döndürür.


Bununla birlikte, dosya tanımlayıcıları sadece dosyalar için değil, aynı zamanda ağ soketleri, cihazlar, hatta bazen işlemler ve hafıza alanları gibi diğer sistem kaynakları için de kullanılır. Bu, işletim sisteminin bu kaynakları birleşik bir şekilde yönetmesini sağlar. Bu nedenle, dosya tanımlayıcıları genellikle “kaynak tanımlayıcıları” olarak da adlandırılır

# read() Fonksiyonu
 Bu fonksiyon ,bir dosyadan belirli bir miktar veriyi okumak için kullanılır.` unistd.h` kütüphanesinde tanımlanmıştır ve genellikle `fcntl.h `ile birlikte kullanılır.
 ```bash
ssize_t read(int fd, void *buf, size_t count);
 ```
- `fd:` Okuma yapılacak dosyanın dosya tanımlayıcısı (file descriptor).
- `buf:` Okunan verinin saklanacağı bellek alanının adresi.
- `count:` Okunacak bayt sayısı.

`ssize_t:` Bu tür, özellikle Unix sistem çağrıları ve diğer bazı işlevler tarafından döndürülen değerler için kullanılır. `ssize_t` türü, `ssize_t` değerlerinin negatif olabileceği bir tamsayı türüdür.`ssize_t`, özellikle okuma ve yazma işlemleri sırasında hata durumlarını ve dosya sonunu (-1, 0, 1, 2, vb.) temsil etmek için kullanılır.

Yani, `ssize_t` türü özellikle işlemlerin başarı durumunu, hata durumunu veya özel durumları belirtmek için tasarlanmış bir türdür, bu nedenle negatif değerleri temsil edebilir. `size_t` ise pozitif tamsayı değerlerini temsil etmek üzere kullanılır ve genellikle bellek boyutları ve indeksleri ifade etmek için kullanılır.

read fonksiyonu okunan byte sayısını (pozitif bir tamsayı olarak) döndürür. Bu değer, 0'dan farklı bir pozitif sayı olacaktır.
- 0: Dosya sonuna ulaşıldığında veya okuma işlemi sırasında veri kalmadığında, read fonksiyonu 0 döndürür.
- -1: Bir hata durumu oluştuğunda, read fonksiyonu -1 döndürür ve errno değişkeni ilgili hata kodunu içerir. Hata kodları, dosya sonuna ulaşma, dosya tanımlayıcısı hatası, okuma izinleri gibi durumları belirtebilir.

Read fonksiyonu, her çağrıldığında dosyanın kaldığı yerden devam eder-dosyayı close() ile kapatmadığın sürece- . Bu nedenle bir önceki çağrının bittiği konumdan sonraki veriyi okumaya devam eder.


# lseek() Fonksiyonu 
Unix benzeri işletim sistemlerinde dosya imlecini konumlandırmak için kullanılan bir sistem çağrısıdır. Bu fonksiyon, dosya içinde okuma veya yazma işlemleri yapmadan önce dosya imlecini belirli bir konuma getirmek için kullanılır.

 ```bash
off_t lseek(int fd, off_t offset, int whence);
 ```

- fd: Dosya tanımlayıcısı (file descriptor).
- offset: Konumlandırma yapılacak yerden itibaren ofset değeri.
- whence: Konumlandırma işleminin nasıl yapılacağını belirten bir değer. SEEK_SET dosyanın başından itibaren, SEEK_CUR mevcut konumdan itibaren, SEEK_END dosyanın sonundan itibaren konumlandırmayı ifade eder.

Bu fonksiyon, dosya imlecinin pozisyonunu ayarlamak için kullanıldığından, dosyadan veri okuma veya yazma işlemleri öncesinde dosya imlecini doğru konuma getirmek için önemlidir.

# Dosya Tanımlayıcısı ile İşaretçisi arasındaki fark (file descriptor & file pointer)? 

Dosya tanımlayıcısı ve dosya işaretçisi arasındaki fark, genellikle işletim sistemi ve programlama dilinin standart kütüphanesi arasındaki farkı yansıtır
Dosya tanımlayıcısı, Linux ve Unix gibi işletim sistemlerinde, açık bir dosyayı (veya herhangi bir soketi) çekirdek düzeyinde tanımlamak için kullanılan düşük seviyeli bir tamsayıdır. Dosya tanımlayıcıları, sistemdeki bir dosyanın bellekteki adresini belirtir.

Dosya işaretçisi, bir C standart kütüphanesi inşa eden bir işaretçidir ve bir dosyayı temsil etmek için kullanılır. FILE, dosya tanımlayıcısını sarar ve tamponlama ve diğer özellikleri ekler.
File pointer, file descriptor’ı sarar ve I/O işlemlerini kolaylaştırmak için arabellekleme ve diğer özellikler ekler.

Özetle, dosya tanımlayıcısı, işletim sistemi düzeyinde bir dosyayı tanımlar, dosya işaretçisi ise programlama dilinin standart kütüphanesi düzeyinde bir dosyayı temsil eder. Her ikisi de dosya I/O işlemlerinde kullanılır, ancak farklı seviyelerde ve farklı şekillerde.



# Statik değişkenler nedir?
Statik değişkenler, kapsam dışına çıktıktan sonra bile değerlerini koruma özelliğine sahiptir. Dolayısıyla, statik bir değişken önceki kapsamındaki önceki değerini korur ve yeni kapsamda yeniden başlatılmaz.

C dilinde static değişkenler varsayılan olarak 0 değerine sahip olur ancak global değişkenler başlangıçta bir değere atanmazlar bu nedenle çöp değer içerirler. Bu,değişkenin bellekteki konumunda ne olursa olsun orada ne varsa o değeri alacakları anlamına gelir. Bu nedenle, her zaman yerel değişkenleri kullanmadan önce bir değere atamak önemlidir. Aksi takdirde, beklenmeyen sonuçlar ortaya çıkabilir.

Statik bir değişkeni başlatırken, değer hesaplama veya işlem içeren bir ifade kullanamazsınız.

# Buffer
Buffer(Tampon bellek),verilerin I/O (giriş/çıkış) işlemlerinden sonra belleğe yazılmadan önce geçici bir alanda bekletildiği bir tampon bölgedir.Bufferlar, I/O işlemlerinin daha verimli ve hızlı olmasını sağlar.
Bellekten okuma ve belleğe yazma işlemleri maliyetlidir. Bufferlar, bu işlemleri daha etkin hale getirir.
Örneğin, dosyadan veri okurken tüm veriyi anında belleğe yazmak yerine, belirli bir boyutta bufferda toplar ve daha sonra toplu olarak belleğe yazarız. Bu performansı artırır.

Buffer size, bir bellek bloğunun veya dizi elemanlarının toplam sayısını ifade eder. Bu terim, genellikle bir veri kümesini veya akışını geçici olarak saklamak için ayrılan bellek alanını ifade eder. Buffer, bir kaynaktan gelen verilerin geçici olarak depolanmasını sağlar, ardından bu verileri başka bir kaynağa veya işleme aktarabilir.

Özellikle read veya write fonksiyonları kullanılırken, bellekte bir geçici depolama alanı (buffer) kullanmak yaygındır.Bu işlemler sırasında bellek alanının boyutu, buffer size olarak adlandırılır.

Kısaca, Buffer, verileri geçici olarak saklamak için kullanılan bir bellek alanıdır. Buffer size, bu bellek alanının boyutunu belirtir ve tek seferde bu kadar veriyi tutabilir. C dilinde buffer kullanmak için `malloc` veya `calloc` gibi fonksiyonlar kullanılabilir. İsim verilmeden de tanımlanabilir.

# Bellek sızıntısı nedir?
Programcılar bir yığında bellek oluşturduğunda ve onu silmeyi unuttuğunda bellek sızıntısı meydana gelir.Bellek sızıntılarını önlemek için, yığında ayrılan belleğin artık ihtiyaç duyulmadığında her zaman serbest bırakılması gerekir(free()).


 ```bash
void f()
{
    int* ptr = (int*)malloc(sizeof(int));
 
    /* Do some work */
 
    /* Return without freeing ptr*/
    return;
}
 ```

# Kütüphane Ekleme

C ve C++ dillerinde, #include direktifi ile bir kütüphaneyi dahil ederken <> ve "" arasında bir fark vardır.

- #include <kütüphane>: Bu şekilde bir kütüphane dahil edildiğinde, derleyici öncelikle sistem kütüphanelerinin bulunduğu dizinlerde belirtilen kütüphaneyi arar. Bu genellikle standart kütüphaneler için kullanılır. Örneğin,` #include <stdio.h>`.

- #include "kütüphane": Bu şekilde bir kütüphane dahil edildiğinde, derleyici öncelikle kütüphaneyi mevcut dizinde arar. Eğer bulamazsa, sistem kütüphanelerinin bulunduğu dizinlerde arama yapar. Bu genellikle kullanıcının oluşturduğu başlık dosyaları için kullanılır. Örneğin,` #include "my_header.h"`.
  



# ............................................

notlar 
-- dosya tanımlayıcısı ile inodeler arasındaki fark----
Dosya Tanımlayıcıları, dosyalarla etkileşim için geçici, çalışma zamanı geçişleriniz gibidir; Inode'lar ise tüm önemli ayrıntıları tutan kalıcı sahne arkası kimlikleridir.

İlişki
İşte nasıl etkileşimde bulundukları:
 
Dosya Açma : Bir dosyayı açtığınızda, işletim sistemi dosyanın meta verilerini almak için Inode'u arar ve ardından gelecekteki işlemler için bir Dosya Tanımlayıcı sağlar.
Okuma/Yazma : Bir FD kullanarak okuduğunuzda veya yazdığınızda, işletim sistemi, diskteki verilerin nerede okunacağını/yazılacağını bulmak için Inode'a başvurur.
Çoklu Erişim : Farklı işlemler aynı dosyayı açtığında veya bir dosyanın birden fazla sabit bağlantısı olduğunda birden fazla FD aynı Inode'a işaret edebilir.



