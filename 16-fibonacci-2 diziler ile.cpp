#include<iostream>
using namespace std;
 
// fibonacci serileri 2-dizi ile

int main() { 
 
	int iterasyon;
	cout << "iterasyon :";
	cin >> iterasyon;
	int* dizi = new int[iterasyon];
	dizi[0] = 0;
	dizi[1] = 1;
	for (int i = 2; i < iterasyon; i++) {
		dizi[i] = dizi[i - 1] + dizi[i - 2];
	}
	for (int i = 0; i < iterasyon; i++) {
		cout << dizi[i] << " ";
	}

	return 0;
}