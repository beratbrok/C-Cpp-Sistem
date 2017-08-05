#include<iostream>
using namespace std;
int main() {

	//  ters ucgen

	int sayi;
	cout << "kenar uzunlugu :";
	cin >> sayi;
	for (int i = 0; i < sayi; i++) {
		for (int j = 0; j < i; j++)cout << " ";
		for (int k = sayi; k > i; k--)cout << "*";
		cout << endl;
	}




	return 0;
}