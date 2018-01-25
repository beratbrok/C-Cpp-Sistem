 
#include <cstdlib>
#include<iostream>
#include<math.h>
using namespace std;

/*
 * 1 3 5 4 dizisi verilsin
 * 1. eleman ile diger elemanlari karsilastirir ve buyukluge gore yer degistirir
 * daha sonra 2. eleman ile 3..n e kadar olanlari karsilastirir aynisini yapar 

*/
int main() {

    srand(time(0));
    
    int dizi[] = {rand()%10,rand()%10,rand()%10,rand()%10};
    
    cout<<"dizi :";
    for(int i = 0 ; i < 4; i++)
    cout<<dizi[i]<<" ";
    cout<<endl;
    
    // selection sort
    int temp;
    for(int i=0;i<4;i++){
        
        for(int j=i;j<4;j++){
            if(dizi[i] > dizi[j]){
                temp=dizi[j];
                dizi[j] = dizi[i];
                dizi[i] = temp;
            }
                
        }
    }
    
    
    cout<<"dizi2 :";
    for(int i = 0 ; i < 4; i++)
    cout<<dizi[i]<<" ";
    cout<<endl;
    
    return 0;
}

