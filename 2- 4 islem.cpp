// 2 sayının toplanması
// girilen 2 sayının 4 işlem formu.
#include<iostream>
using namespace std;
int main(){
	
	/* 
		int sayi1 = 3;
		int sayi2 = 5;
		cout<<sayi1+sayi2<<endl;
	
	*/
	int sayi3 , sayi4;
	
	cout<<"Sayi 1:";
	 
	cin>>sayi3;
	
	cout<<endl<<"Sayi 2:" ;						// \n ifadesi ile endl ifadesi satır sonu olduğunu
												// imlecin 1 satır alttan devam edeceğini gosterir.
	cin>>sayi4;
	
	cout<<"\nToplam :"<<sayi3+sayi4<<endl;
	cout<<"Fark :"<<sayi3-sayi4<<endl;
	cout<<"Carpim :"<<sayi3*sayi4<<endl;
	cout<<"Bolum :"<<sayi3/sayi4<<endl;
	
	// bolmede dikkat edilecek husus tip donusumleridir ! bu konuya ileride değineceğiz.
	
	
}
