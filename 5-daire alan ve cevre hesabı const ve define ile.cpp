#include<iostream>
using namespace std;

#define pi 3.14

int main() {		// Dairenin cevresi ve alan hesabý
	const float yaricap = 5;

	cout << "Alan :" << pi*yaricap*yaricap << endl;
	cout << "Cevre :" << 2 * pi*yaricap << endl;

	
	getchar();
	return 0;
}