#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    srand(time(0));
    int dizi[10];
    for(int i=0;i<10;i++){
        dizi[i] = rand()%10; 
    }
    
    printf("Girilen dizi :"); 
    
    for(int i=0;i<10;i++)
        printf("%d ",dizi[i]); 

    printf("\n");

    // siralama algoritmasi
    // en kucugu bul en bastaki ile yer degistir eleman ilerle
    int enKucuk;
    int temp;

    for(int i=0;i<10;i++){

        enKucuk = i;
        
        for(int j=i;j<10;j++)
            if(dizi[enKucuk] > dizi[j])
                enKucuk = j;

        // swap
        temp = dizi[enKucuk];
        dizi[enKucuk] = dizi[i];
        dizi[i] = temp;
    }
    printf("Duzenlenmis dizi ..:");
    for(int i=0;i<10;i++)
        printf("%d ",dizi[i]); 

        
    getchar();
    return 0;
}
