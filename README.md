# Dosya Nedir?

Dosya bilgileri genellikle dosyanın kendisi içinde değil, işletim sistemi tarafından yönetilen bir dosya sistemi içinde tutulur. Bu bilgiler genellikle “meta veri” olarak adlandırılır ve dosya adı, oluşturma tarihi, son değiştirilme tarihi, dosya boyutu ve sahibi gibi bilgileri içerir.Dosya üst bilgileri (oluşturma tarihi, son değişiklik tarihi...) meta veriler olarka adlandırılır.

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

open():

close():  Açık dosya tanımlayıcılarını kapatır (soketler dahil). Bu, işletim sistemine, o dosya tanımlayıcısı veya soket için ayrılan kaynakları serbest bırakmasını söyler.



Bununla birlikte, dosya tanımlayıcıları sadece dosyalar için değil, aynı zamanda ağ soketleri, cihazlar, hatta bazen işlemler ve hafıza alanları gibi diğer sistem kaynakları için de kullanılır. Bu, işletim sisteminin bu kaynakları birleşik bir şekilde yönetmesini sağlar. Bu nedenle, dosya tanımlayıcıları genellikle “kaynak tanımlayıcıları” olarak da adlandırılır


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
  


# ............................................

notlar 
-- dosya tanımlayıcısı ile inodeler arasındaki fark----
Dosya Tanımlayıcıları, dosyalarla etkileşim için geçici, çalışma zamanı geçişleriniz gibidir; Inode'lar ise tüm önemli ayrıntıları tutan kalıcı sahne arkası kimlikleridir.

İlişki
İşte nasıl etkileşimde bulundukları:
 
Dosya Açma : Bir dosyayı açtığınızda, işletim sistemi dosyanın meta verilerini almak için Inode'u arar ve ardından gelecekteki işlemler için bir Dosya Tanımlayıcı sağlar.
Okuma/Yazma : Bir FD kullanarak okuduğunuzda veya yazdığınızda, işletim sistemi, diskteki verilerin nerede okunacağını/yazılacağını bulmak için Inode'a başvurur.
Çoklu Erişim : Farklı işlemler aynı dosyayı açtığında veya bir dosyanın birden fazla sabit bağlantısı olduğunda birden fazla FD aynı Inode'a işaret edebilir.



