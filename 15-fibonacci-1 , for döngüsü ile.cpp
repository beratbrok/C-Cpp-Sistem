#include<iostream>
using namespace std;
 
// fibonacci serileri 1-d�ng�ler ile

int main() { 
	
	int alt=0, ust=1, toplam=0;
	
	int iterasyon;
	cout << "iterasyon :";
	cin >> iterasyon;
	for (int i = 0; i < iterasyon; i++) {
		cout << alt << " ";
		toplam = alt + ust;
		alt = ust;
		ust = toplam;
	}



	return 0;
}