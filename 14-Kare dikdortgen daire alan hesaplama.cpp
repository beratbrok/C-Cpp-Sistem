#include<iostream>
using namespace std;

float daire_alan(float yaricap) {
	return 3.14*yaricap*yaricap;
}
int kare_alan(int kenar) {
	return kenar*kenar;
}
int dikdortgen_alan(int kisa_kenar,int uzun_kenar) {
	return kisa_kenar*uzun_kenar;
}
void alanYazdir(float alan) {
	cout << endl<< "Alan :" << alan << endl;
}

int main() {
	// Kullanýcý secimine gore alana hesaplama
	int secim = NULL;
	cout << "1-Daire Alani\n2-Kare Alani\n3-Dikdortgen Alani\n\t\tSecim :";
	cin >> secim;
	switch (secim)
	{
	case 1: {
		cout << "Yaricap :";
		float yaricap;
		cin >> yaricap;
		alanYazdir(daire_alan(yaricap));
	}break;
	case 2: {
		cout << "Kenar :";
		int knr;
		cin >> knr;
		alanYazdir(kare_alan(knr));
	}break;
		
	case 3: {
		cout << "kisa :";
		int kisa, uzun;
		cin >> kisa;
		cout << "uzun :";
		cin >> uzun;
		alanYazdir(dikdortgen_alan(kisa, uzun));
	}break;
	default: {
		cout << "Bilinmeyen secim" << endl;
	}break;
	}

	



	return 0;
}