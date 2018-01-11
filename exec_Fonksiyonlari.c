// fonksyionlar execl execv execvp execlp execle execve.. diye devam eder.
// şimdi bu fonksiyonlarin nasıl calistigina bakalim
// Başlamadan once bilmemiz gereken şey bir proses  exec fonksiyonlarindan herhangi birisini calistirirsa
// mevcut prosesin icerigi bosaltilir ve proses sadece exec ile verilen gorevi yerine getiren bir proses olur.
// mesela exec fonksiyonlarından herhangi birisinden sonra printf("hello") ifadesi yer alsın.
// exec fonksiyonundan sonra prosesin icerigi silinecegi ve prosesin tek görevi exec de bulunan komutları icraa etmek olacagindan
// exec'den sonra gelen ifadelerin hicbirisi calistirilmaz sık sık altnı cizdigim gibi exec den sonra proses eski proses degildir. degismistir !
Execl fonksiyonu

prototip :int execl(const char *path, const char *arg0, ...);
calistirilacak dosyanin yolunu ve argümanlarini aliyor. sondaki 3. isareti (...) degisken sayida argüman alabilecegini gosteriyor
argüman listesi null ile bitmelidir.
	// ornek olarak ekrana hello world yazan bir programi calistiracak baska bir program yazalim
// merhaba.c			// Program.c
include<stdio.h>		include<stdio.h>				
int main(){			int main(){

printf("HEllo world");		execl("/home/osman/Masaüstü/merhaba",NULL);
				
getchar();			return 0;
return 0;			}
}

merhaba.c dosyasi derlendikten sonra calistirilabilir program olan merhaba olusur.
	Program.c dosyasinda execl fonksiyonu merhaba(.exe) programini calistirir
	// ls -l ornegi
	execl("bin/ls","ls","-l","home/osman/Masaüstü",NULL);

Execv fonksiyonu ise execl'in birebir benzeridir. aralarındaki fark execv argümanları bir dizi biciminde alıyor
	prototip :int execv(const char *path, char *const argv[]);
/* exectest2.c */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
 
int main(void)
{
    char *args[] = {"/bin/ls", "-l", NULL};
  
    if (execv("/bin/ls", args) < 0) {
        perror("execv");
        exit(EXIT_FAILURE);
    }
          
    printf("Tamam\n");
          
    return 0;
}

Execlp fonksiyonu execv ve execl fonksiyonlarinin PATH 'i tanimli versiyonudur.
yani sadece calistirilacak olan dosyanin adinin yazilmasi yeterlidir , proses bu dosyayi kendi tanimlanmis PATH yerlerinde arar

	prototip :int execlp(const char *file, const char *arg0, ...);

if (execlp("ls", "ls", "-ls", (char *) 0) < 0) {
    perror("execlp");
    exit(EXIT_FAILURE);
}

Prosesin PATH çevre değişkeninin aşağıdaki gibi olduğunu varsayalım:

PATH=/usr/local/bin:/usr/bin:/bin:/usr/bin/X11

PATH çevre değişkeni ‘:’ karakterleriyle ayrıştırılmış alanlardan oluşmaktadır.
Bu alanlarda dizinlerin yol ifadeleri bulunur. 
exec fonksiyonlarının p’li biçimleri PATH çevre değişkenindeki bu alanları sırasıyla gözden geçirirler. 
Bu örneğimizde “ls” program dosyası önce “/usr/local/bin” dizini içerisinde, sonra “/usr/bin” dizini içerisinde aranacak ve arama işlemi böyle sürdürülecektir. 
Bu aramalar sırasında dosya bulunursa arama devam etmeyecektir. 
(ls program dosyasının /bin dizininde bulunduğunu anımsayınız.) 
Burada önemli olan bir noktaya dikkatinizi çekmek istiyoruz. exec fonksiyonlarının p’li biçimleri prosesin çalışma dizinine hiç bakmamaktadır. 
Yani PATH çevre değişkeninin yukarıdaki gibi bir içeriğe sahip olduğu durumda biz çalışma dizinindeki bir programı exec fonksiyonlarının p’li biçimleriyle çalıştıramayız. 
Fakat PATH çevre değişkeninde ‘.’ ifadesi ile prosesin çalışma dizini için de yol belirtilebilir. 
	
exec fonksiyonlarının p’li biçimlerinde belirtilen program dosyasına ilişkin yol ifadesi herhangi bir yerinde ‘/’ karakteri içeriyorsa bu durumda PATH çevre değişkenine bakılmaz.
Bu durumda yol ifadesi mutlaksa kök dizinden, göreliyse prosesin çalışma dizininden itibaren yer belirtir. Örneğin:

if (execlp("project/sample", "project/samples", NULL < 0) {
    perror("execlp");
    exit(EXIT_FAILURE);
}

    
Execvp fonksiyonu ise execlp fonksiyonunun parametrelerini dizi biciminde alan versiyonudur.
    
    prototip :int execvp(const char *file, char *const argv[]);
    
    /* exectest4.c */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
 
int main(void)
{
    char *args[] = {"ls", "-l", NULL};
 
    if (execvp("ls", args) < 0) {
        perror("execvp");
        exit(EXIT_FAILURE);
    }
           
    return 0;
}
    
    
    
    
    
    
    

