#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{  
    
    
    int pid , fd1 , fd2 , boyut;
    
    struct stat st;
    char g[100] , *veri;
      
    // acilacak dosyanin adi
    
    gets(g);
    
    fd1 = open(g , O_RDWR | O_CREAT);   // hem okuma hem yazma icin ac.
    fd2 = dup(fd1);         // dosya temsilcisini kopyala.
    
    fstat(fd1,&st);         // dosya bilgilerini al.
    boyut = (int)st.st_size;// dosya boyutu aliniyor.
    
    printf("Boyut 1 :%d\n",boyut);
    
    pid = fork();   // proses olustur.
    
    if(pid == 0){   // cocuk proses dosyaya ekleme islemi yapacak
        
        // imlec dosya basindan dosya boyutu kadar ilerletilecek. burada dosya boyutu bulunuyor.
        lseek(fd1,boyut,SEEK_SET);
        
        write(fd1,"lseek fonksiyonu gonderdi!!!\n",29);
         
    }
    else{
        
        wait(pid);  // dosyaya yazilmadan anne proses okuma yapmasin
        
        fstat(fd2,&st); // dosyanin yeni bilgileri aliniyor.
        
        boyut = (int) st.st_size;
        printf("Boyut 2: %d\n",boyut);
        
        veri = (char*) malloc(sizeof(char)*boyut);
        
        lseek(fd2,0,SEEK_SET);  // imlec basa aliniyor
        read(fd2,veri,boyut);
        printf(veri);
        printf("\n");
        free(veri);
         
    }
    
    
    return 0;
}
