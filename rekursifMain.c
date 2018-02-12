#include <stdio.h>

int i;
int enSon;

int main(){

	if(i++ == 10 ) return 0;
	enSon++;
	int data = main(); 
	
	printf("Hell world %d\t%d\n",data , enSon);
	enSon --; 

return 0;
}

/*
  Normalde main fonksiyonu yanlizca 1 defa cagarilan bir fonksiyondur.
  biz burada bu kurali yiktik :)
  kod incelenirse en son cagarilan main fonksiyonu geriye return 0 degerini donduruyor ve bir onceki fonksiyon kaldigi yerden 
  devam ediyor.ilk calisan main ise return 0 ile programi bellege geri gonderiyor.
*/
