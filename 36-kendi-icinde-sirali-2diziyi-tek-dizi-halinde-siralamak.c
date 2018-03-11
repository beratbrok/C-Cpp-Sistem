#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(){
 
    srand(time(NULL));

    int dizi1[5] = {6,8,10,12,14};
    int dizi2[10] = {1,2,3,6,8,9,15,16,22,23};

     

        printf("dizi1 :");
    for(int i=0;i<5;i++)
        printf("%d ",dizi1[i]);
        printf("\tdizi2 :");
    for(int i=0;i<10;i++)
        printf("%d ",dizi2[i]);

        printf("\n\n");
    int siraliDizi[15];

    int p,q,m,n,k;
    p = 0;
    q = 4;
    m = 0;
    n = 14;
    k = 0;
    
    while(p<=q && m<=n){
        if(dizi1[p] < dizi2[m]){
            siraliDizi[k] = dizi1[p];
            p++;
        }
        else{
            siraliDizi[k] = dizi2[m];
            m++;
        }
        k++;
    }
    if(p > q){
        for(int i = m ; i<15;i++)
            siraliDizi[k++] = dizi2[i];
    }else if(m > n){
        for(int i=p;i<5;i++)
            siraliDizi[k++] = dizi1[i];
    }
    printf("sirali : ");
    for(int i=0;i<15;i++)
        printf("%d ",siraliDizi[i]);

    return 0;
}



