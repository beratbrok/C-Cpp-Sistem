#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <signal.h>

//##################### On Tanımlamalar ##################################################################################################

int giris_bekle();

char* satir_oku();

char** okunan_degeri_parcala();
   
int girilen_stringin_dizi_indexini_dondur(char**);

int calistir(char**);

int dosya_oku(char** komut, char* satir);

int dosya_yaz(char** komut, char* satir);

int kelimeBoyutu;

char* satir;

//########################################################################################################################################








//########################################################################################################################################

int main(int argc, char** argv) {
 

    int contin = 1;
    
    do{
    
         contin =  giris_bekle();
 
    
    }while(contin != 0);
    
    printf("Terminal sonlandirildi ...:true");
 
    
    return (EXIT_SUCCESS);
}

//########################################################################################################################################












//###################################################<   FONKSİYON GOVDELERİ  >###########################################################












//########################################################################################################################################

/*
 <
 Bu fonksiyon main icerisinde calistirilan tek fonksiyondur. amaci disaridan girilen degerleri alimak , alinan degerleri
 
 kelime kelime parcalayip bir string dizisine koymak , ve bu degerleri calistirmaktir. 3 gorevi de bir bunyede toplar.
 >
 */

int giris_bekle(){
    
    
    char* satir;
     
    printf(">");
    
    satir = satir_oku();
    
    char** kelimeler = okunan_degeri_parcala(satir);
    
    int cont = calistir(kelimeler);
     
    return cont;
}


//########################################################################################################################################










//########################################################################################################################################

/*
 <
 Bu fonksiyon disaridan girilen degerleri bir string e koyar.
 
 Bosluk ifadelerini de aynen okur.
 
 >
 */


char* satir_oku(){
    
    int index = 0;
    
    const int metin_uzunlugu = 500;
     
    char* metin = malloc(sizeof(char)*metin_uzunlugu);
    
    int ch;
    
    while(1){ 
        
        ch = getchar(); 
        
        if(ch == '\n'){ metin[index] = '\0'; return metin;} 
        
        else metin[index++] = ch;
    }
    
    satir = metin;
    
}





//########################################################################################################################################













//########################################################################################################################################

/* < Bu fonksiyon aldigi satiri char dizisine kelime kelime koyar ve en sonunda char dizisi geriye döndürür.
 * Bu dizinin her bir indexinde , satirdaki bir kelime bulunur. >


*/
char** okunan_degeri_parcala(char* satir){
 
    int kelime_adedi = 0; 

    char* pch;
    
    char** kelimeler = malloc(sizeof(char*) * 20);
    
    pch = strtok(satir," ");
    
    while(pch !=NULL){
        
        kelimeler[kelime_adedi++] = pch;
        
        pch = strtok(NULL," ");
        
    }
    kelimeler[kelime_adedi] = NULL;
    
    kelimeBoyutu = kelime_adedi;
    
    return kelimeler;
    
}

//########################################################################################################################################













//########################################################################################################################################

/*
 < Bu fonksiyon bir string dizisi alır. 
 * Eğer string dizisinin ilk elemanı "quit" ise , program sonlanır
 * Eğer string dizisinin ilk elemanı "cd" yani dizin değiştirme komutu ise , komut[1] yani parametreleri alır ve chdir() fonksiyonunda calistirir.
 * Eger komut quit veya cd degil ise , baska bir islem yapilacagi anlasilir. Bir proses fork() ederiz 
 * Eger komutumuzda ">" veya "<" gibi isaretler buluyor ise , dosya islemi yapacagimizi anliyoruz.
 * bunun icin  ilgili dosya olusturma ve / veya dosya yazma fonksiyonlari , child proses ile cagariliyor.
 * eger komutumuzda > < isaretleri bulunmuyorsa , komut temel komut olarak ele alinir ve child proses icerisindeki execvp() komutu ile calistirilir.
 * child proses gorevini tamamlayana kadar , ana proses wait(NULL) komutunu calistirir. daha sonra fonksiyon biter ve kullanicidan yeni bir komut bekler (giris_bekle())
 * 
 
 */

int calistir(char** komut){
 
     
    if(!strcmp(komut[0],"quit")){       // quit gelirse , proseslerin sonuclanmasini bekle ven sonlan..
        
        wait(NULL) ;
        
        return 0;
    }
    if(!strcmp(komut[0],"cd")){
        
        if (chdir(komut[1]) != 0) {
            
      perror("lsh");
      
    }
        return 1;
    }
            
     
    
    else{
        
        int pid = fork();

        if(pid == 0){
            // child proses
            
            if(kelimeBoyutu > 2){
            
            if(!strcmp(komut[kelimeBoyutu -2 ],"<")){
                 dosya_oku(komut,satir);
                
            }
            else if (!strcmp(komut[kelimeBoyutu -2 ],">")){
                dosya_yaz(komut,satir);
            }
            
            }
            else{ 
 
            int i =   execvp(komut[0],komut);

            if( i == -1) perror("hata");
            
            return 1;
            
            }
            exit(0);    // cocuk proses geri dondur.
        }
        
        if(pid > 0){
            // perent proses
            
            wait(NULL); // cocuklar bitmeden calisma

        }

         return 1; 
    }
}

//########################################################################################################################################










//########################################################################################################################################

/*
 * <Dosya okuma islemleri icin bu fonksiyon calisir.
 Temel olarak alinan giris satiri ve parcalanmis giris satiri string dizisi uzerinden islem yapar.
 * fonksiyon giris komutundaki ilk ve son kelimeleri( < a.txt) disinda kalan "istenilen" bolgeyi bir string dizisine kaydeder 
 daha sonra dup2 fonksiyon kullanilarak yonlendirme yapilir. metin dosyadan okunur
 * eger istenilen dosya yok ise hata verir
 */

int dosya_oku(char** komut, char* satir){
    
        int boyut = 0; 
	char* pch;
	char** kelimeler = malloc(sizeof(char*) * 20);

	for(int i=0;i<kelimeBoyutu-2;i++){
		pch = komut[i];
		kelimeler[boyut++] = pch;
	}

	kelimeler[boyut] = NULL;
        
      
        
	
        FILE* fp = fopen(komut[kelimeBoyutu-1],"r");
        if(!fp){
            printf("Dosya bulunamadı...\n");
            return 1;
            
        }
        else{
            
            if(!strcmp(komut[0],"increment")){
                
            int tamsayi = 0;
            
            fscanf(fp,"%d",&tamsayi);
            
            fclose(fp);
            
            tamsayi++;
 
            remove(komut[kelimeBoyutu-1]);
             
            fp = fopen(komut[kelimeBoyutu-1],"w");
            
            fprintf(fp,"%d\n",tamsayi);
            
            fclose(fp);
            
            int fileDesc = open(komut[kelimeBoyutu-1],O_RDWR,0600);	 	 
            if(fileDesc<0) printf("hata");
            if(dup2(fileDesc,0) < 0);
	    execvp("cat",kelimeler);
            
            
            return 1;
             
            }
            
            else{
	    int fileDesc = open(komut[kelimeBoyutu-1],O_RDWR,0600);	 	 
            if(fileDesc<0) printf("hata");
            if(dup2(fileDesc,0) < 0);
	    execvp(komut[0],kelimeler);
       
            close(fileDesc);
	return 1;
            }
        }
}




//########################################################################################################################################









//########################################################################################################################################


/*
 * <Dosya yazma islemleri icin bu fonksiyon calisir.
 Temel olarak alinan giris satiri ve parcalanmis giris satiri string dizisi uzerinden islem yapar.
 * fonksiyon giris komutundaki ilk ve son kelimeleri( > a.txt) <disinda kalan "istenilen" bolgeyi bir string dizisine kaydeder 
 daha sonra dup2 fonksiyon kullanilarak yonlendirme yapilir. metin dosyaya yazilir
 * eger istenilen dosya yok ise dosya otomatik olarak olusturulur. eger istenilen dosya var ise metini sona ekler
 */



int dosya_yaz(char** komut, char* satir){
        int boyut = 0; 
	char* pch;
	char** kelimeler = malloc(sizeof(char*) * 20);
        
	for(int i=0;i<kelimeBoyutu-2;i++){
		pch = komut[i];
		kelimeler[boyut++] = pch;
	}

	kelimeler[boyut] = NULL;
	
	 
	    int fileDesc = open(komut[kelimeBoyutu-1],O_RDWR|O_CREAT|O_APPEND,0600); 
            if(fileDesc<0) printf("hata");
            if(dup2(fileDesc,1) < 0);
	    execvp(komut[0],kelimeler);
       
            close(fileDesc);
	return 1;
}

//########################################################################################################################################
