#include<iostream> 
#include<iomanip>
using namespace std;

int main() {		 
					
	int sayi = 2000;
	bool asalmi = true;
	for(int i=2;i<2000;i++){
	for(int j=2;j<i;j++){
	if(i%j==0) asalmi =false;
	}
		
	if(asalmi){
	cout<<i<<endl;
	}
	asalmi=true;
	}



	getchar();
	return 0;
}
