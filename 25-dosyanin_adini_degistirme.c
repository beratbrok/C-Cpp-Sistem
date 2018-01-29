#include <sys/time.h>
#include <fcntl.h>
#include <linux/kd.h>
#include <linux/types.h>
#include <unistd.h>
#include <stdio.h>



int main() {
	  
    // istenilen bir programin adini degistiren kod
    
    char eskiAd[100] , yeniAd[100];
    
    printf("Eski programin dizini ve adi :");
    gets(eskiAd);
    printf("Yeni programin adi :");
    gets(yeniAd);
     
    int degistir = rename(eskiAd,yeniAd);
    if(degistir == -1)
        printf("Err!!");
    else printf("Dosya adi degistirildi");
    
}
