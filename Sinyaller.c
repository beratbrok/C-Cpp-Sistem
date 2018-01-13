prototip : signal(int signum , void fonk) ---> sinyalin yakalanmasi ve ilgili foksiyonun cagarilmasi
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void sigint_yakala(){
    printf("\nCTRL-C tusuna basildi...\n");
}

void main(){
    
    while(1){
    
    
    // CTRL-C signali yakalayan program
    
        if(signal(SIGINT,sigint_yakala) == SIG_ERR){
            printf("Signal yakalanamadi.");
        }
        
    } 
    exit(EXIT_SUCCESS);
}

prototip : sigaction(int signum , struct sigaction* yeni_islem , struct sigaction* eski_islem);
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void sinyal_yakala(int signum){
    printf("\tSinyal Yakalandi...%d\n",signum);
}

void main(){
    
    struct sigaction yeni_islem , eski_islem;
    
    yeni_islem.sa_handler = sinyal_yakala;
     
    while(1){
    
        sigaction(SIGINT,&yeni_islem , &eski_islem);
        
    }
    
    exit(EXIT_SUCCESS);
}

Prototip : sigprocmask(int tur, const sigset_t* takim , sigset_t* eski_takim)

bu cagri sinyallerin bloklanmasini , bloklanmis sinyallerin serberst birakilmasini ve sinyal setlerinin degistirilmesini saglar
bloklanmis bir sinyal serbest birakilana kadar askida tutulur.
parametrelerini ilki yapilacak islemin turudur. bu parametre SIG_BLOCK , SIH_UNBLOCK , SİG_SETMASK degerlerini alir.
2.parametre sigset_t turunde bir sinyal listesidir 3.parametre sigset_t turunde bir eskisinyal listesini veya NULL degerini alır.

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>


sigset_t blokeSinyaller;


void yakalanan(int signumber){
    
    if(!sigismember(&blokeSinyaller,signumber)){ // eger bloke sinyaller icerisinde degilse , sinyali bloke et
        
        
        sigaddset(&blokeSinyaller,signumber);
        
        sigprocmask(SIG_BLOCK,&blokeSinyaller,NULL);    // sinyal bloke edildi.
        
        printf("%d\tSinyali yakalandi ve bloke edildi.\n",signumber);
        
    }
    else{
        printf("\tSinyal bloke edilmis...\n");
    }
}

void main(){
     
    
    sigemptyset(&blokeSinyaller);
    
    while(1)
        signal(SIGINT,&yakalanan);
        
    exit(EXIT_SUCCESS);
}
// sinyali bloklama ve acma ornegi
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>


sigset_t blokeSinyaller;

int sayac = 0;

void yakalanan(int signumber){
    
    if(!sigismember(&blokeSinyaller,signumber) && sayac == 0){ // eger bloke sinyaller icerisinde degilse , sinyali bloke et
        
        
        sigaddset(&blokeSinyaller,signumber);
        
        sigprocmask(SIG_BLOCK,&blokeSinyaller,NULL);    // sinyal bloke edildi.
        
        printf("%d\tSinyali yakalandi ve bloke edildi.\n",signumber);
        
        sayac = 1;
        
    }
    else if(sayac == 1){
        printf("\tSinyal bloke edilmis bloke sinyal aciliyor...\n");
        sigprocmask(SIG_UNBLOCK,&blokeSinyaller,NULL);
        printf("\tBloke sinyal acildi...\n");
        if(sigismember(&blokeSinyaller,signumber)){
            sigdelset(&blokeSinyaller,signumber);
        }
        sayac = 0;
    }
    
    
    
}

void main(){
     
    
    sigemptyset(&blokeSinyaller);
    
    while(1)
        signal(SIGINT,&yakalanan);
    
    
    
    exit(EXIT_SUCCESS);
}

Prototip : kill(pid_t pid , int signum)

kill sinyali pid si girilen bir proses'e sinyal gondermek icin kullanilir.
prosesler birbirlerine sinyal gonderirler  , burada pid kısmı bir prosesin pid si , signum ise
gonderilmek istenilen sinyal olarak girilir.
ekstra bilgi olarak SIGKILL sinyali gonderilirse , proses sonlanır. bu sinyali diger sinyallerden faklı kılan şey
sinyalin yakalanamıyor ve iptal edilemiyor olmasıdır.

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
 
void main(){
     
   
    int pid = fork();
    
    if(pid == 0){
        printf("Merhaba ben cocuk proses , simdi kendimi sonlandiracagim");
        kill(getpid() , SIGKILL);
    }
    else{
        wait(pid);
        printf("Ben calistigima gore cocugum olmustur. bu aciya katlanamam elveda...\n"
                "kill(%d,SIGKILL) calistiriliyor..\n",getpid());
        kill(getpid(),SIGKILL);
    }
   
    
    exit(EXIT_SUCCESS);
}


















