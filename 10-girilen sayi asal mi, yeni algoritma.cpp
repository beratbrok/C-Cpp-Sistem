/*Hesap makinesi uygulamasidir , kullanicidan sira ile 1 sayi 1 islem 1 sayi alir , islem sonucunu geri dondurur
gorsellik icin system("cls") metodu cesitli yerlerde kullanilmistir
*/



// girilen sayilarin asal olup olmadiklarini bulmak

#include<iostream>

using namespace std;

int main() {
	
	int sayi;
	int sayac = 1;
	while (1) {
		sayac = 1;
		cout << "Asal olup olmadigini bulmak istediginiz sayiyi girin :";
		cin >> sayi;
		if (sayi > 2) {
		while (sayac++ < sayi) {
			 
				if (sayi%sayac == 0) {
					cout << "sayi asal degildir\n";
					break;
				}
				else if (sayac + 1 == sayi) { cout << "sayi asaldir\n"; break; }
			  
		}
		}
		else if (sayi == 2)cout << "sayi asaldir\n";
		else cout << "Bilinmeyen sayi !\n";
		 


	}



	return 0;
}