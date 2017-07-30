#include<iostream> 

using namespace std;

int main() {		 
	 

	int a = 10;

	cout << a << endl;		//	10
	cout << a-- << endl;	//	10
	cout << a << endl;		//  9
	cout << ++a << endl;	//	10
	cout << a << endl;		// 10
	cout << ++a << endl;	// 11
	cout << a << endl;		// a nýn son degeri 11 olacak

	getchar();
	return 0;
}