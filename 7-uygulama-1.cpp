#include<iostream> 
#include<iomanip>
using namespace std;

int main() {		 
					// eliptik
	cout << setw(6) << "***" << endl;
	cout << setw(3) << '*'<< setw(4) << '*' << endl;
	for (int i = 0; i < 2; i++) {
		cout << setw(2) << "*" << setw(6) << "*" << endl;
	}
	cout << setw(3) << '*' << setw(4) << '*' << endl;
	cout << setw(6) << "***" << endl;


	cout << endl;
	cout << endl;

					// dikdortgen
	for (int j = 10; j > 0; j--)cout << "*";
	cout << endl;
	for (int i = 0; i < 5; i++) {
		 
		cout << "*";
		for (int i = 0; i < 9; i++)cout << " ";
		cout << "*" << endl;

	}
	for (int j = 10; j > 0; j--)cout << "*";

	getchar();
	return 0;
}