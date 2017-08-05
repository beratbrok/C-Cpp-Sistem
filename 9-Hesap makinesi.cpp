/*Hesap makinesi uygulamasidir , kullanicidan sira ile 1 sayi 1 islem 1 sayi alir , islem sonucunu geri dondurur
gorsellik icin system("cls") metodu cesitli yerlerde kullanilmistir
*/



#include<iostream>
#include<stdlib.h>	// random fonksiyonlari icin gereklidir
using namespace std;

int main() {

	int sayi1, sayi2;
	char islem;
	char yanit = 'e';

	while (yanit == 'e') {

		system("cls");
		cout << endl << "a+b" << endl;
		
		cin >> sayi1 >> islem >> sayi2;
		 
		system("cls");

		cout << endl << "a+b" << endl;			// gorsellik amaclidir

		cout <<sayi1<<islem<<sayi2 <<" :";

		switch (islem)
		{
		case '+':{
			cout << sayi1 + sayi2 << endl;
		}break;
		case '-': {
			cout << sayi1 - sayi2 << endl;
		}break;
		case '*': {
			cout << sayi1 * sayi2 << endl;
		}break;
		case '/': {
			cout << sayi1 / sayi2 << endl;
		}break;

		}
		cout << "devam ? (e/h) :";
		cin >> yanit;

	}


	return 0;
}