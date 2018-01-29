#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{  
    
    int fd[2] , pid , yazici , okuyucu , statu;
    char bilgi[18];
    
    
    pipe(fd);   // pide den donen fd[0] okumak , fd[1] yazmak icin kullanilir.
    
    pid = fork();
    if(pid == 0){ // cocuk proses
        
        close(fd[0]);
        
        yazici = dup(fd[1]);    // pipe' ile yazmak icin fd[1] i kopyala
        
        printf("Yazici dup donusu :%d\t fd[1] degeri %d\n",yazici,fd[1]);
        
        close(fd[1]);
        write(yazici,"Ben cocuk proses\n",18);
        
        
    }
    else{   // anne proses
        
        close(fd[1]);
        
        okuyucu = dup(fd[0]);
        
        printf("okuyucu dup donusu %d\t fd[0] degeri %d\n",okuyucu , fd[0]);
        
        close(fd[0]);
        
        read(okuyucu,bilgi,18);
        
        printf(bilgi);
        printf("\n");
        
        
    }
    
    
    return 0;
}
