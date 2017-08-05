#include<iostream>
using namespace std;
int main() {

	 // ucgen cizmek
	int boyut;
	cout << "En ve boy :";
	cin >> boyut;

	for (int i = 0; i < boyut; i++) {
		for (int j = boyut; j > i; j--)
			cout << "* ";
		cout << endl;
	}

	return 0;
}