// sezar sifreleme. Bu kodlar osman yasal tarafından yazılmıştır.
#include<iostream>
#include<fstream>
#include<string> 
#include<time.h>
using namespace std;
int main() {
	srand(time(0));
	char devam = 'e';
	while (devam == 'e') {

		cout << "1-Sifrele\n2-Sifre coz\n\tTercih :";
		int tercih;
		cin >> tercih;
		fstream dosya;	// dosya islemleri icin kullanilacak.
		switch (tercih)
		{
		case 1: {
			string metin="";
			string sifreli_metin="";
			
			int iter_sayisi = rand() % 10;	// kac basamak kaydirilacak bilgisi rastgele olarak aliniyor.
			system("cls");
			
			dosya.open("cripto metin.txt", ios::in | ios::out | ios::app);
			if (dosya.is_open() == true) {
				cout << "sifrelenmek istenilen metin.\n";
				cout << "-----------\n";

				cin.ignore();
				getline(cin, metin);	// metin girisi yapiliyor
				sifreli_metin = metin;
				
				for (int i = 0; i < metin.length(); i++) {		// tamami kucuk harflere cevrildi
					if (metin[i] >= 97 && metin[i] <= 122) continue;
					else if (metin[i] < 97 || metin[i]>122) {
						metin[i] = (char)((int)metin[i] + 32);
					}
				}

				for (int i = 0; i < metin.length(); i++) {		// sifreleme bolumu
					int karakter = (int)metin[i];
					if (karakter >= 97 && karakter <= 122) {
						karakter += iter_sayisi;
					}
					sifreli_metin[i] = (char)karakter;
				}
				dosya << sifreli_metin << "...anahtar :"<<iter_sayisi;
				dosya.close();
			}
			else throw "Err !";
		}break;
		case 2: {
			string dosya_ad;
			string metin;
			string sifresiz_metin;
			int anahtar;
			system("cls");
			
			cout << "dosya adi :";
			cin.ignore();		// disaridan sifresi cozulecek dosyanin adi ve iterasyon bilgisi aliniyor
			getline(cin, dosya_ad);
			cout << "iter sayisi :"; 
			cin >> anahtar;
			
			dosya.open(dosya_ad, ios::in | ios::out | ios::app);
			if (dosya.is_open()) {
				getline(dosya, metin);
				metin=metin.substr(0, metin.length()-13);		// metindeki ...anahtar : x degeri siliniyor
				sifresiz_metin = metin;
				
				for (int i = 0; i < metin.length(); i++) {		// sifre cozme bolumu
					int karakter = (int)metin[i];
					karakter -= anahtar;   
					sifresiz_metin[i] = (char)karakter;
					 
				}
				dosya.close();
				dosya.open("cozulmus metin.txt", ios::in | ios::out | ios::app);
				dosya << sifresiz_metin;
				dosya.close();
			}

			else throw "Err";

		}break;

		default:cout << "Gecersiz !";
			break;
		}

		cout << "\nBaska isleminiz var mi ? (e/h) :";
		cin >> devam;
	}

	return 0;
}
