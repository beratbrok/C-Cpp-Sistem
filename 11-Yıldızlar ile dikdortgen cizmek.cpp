#include<iostream>
using namespace std;
int main() {

	// kare cizelim

	int en, boy;

	cout << "En :";
	cin >> en;
	cout << "Boy :";
	cin >> boy;

	for (int i = 0; i < boy; i++) {
		for (int j = 0; j < en; j++) {
			cout << "* ";
		}
		cout << endl;
	}



	return 0;
}