/*

temel veri tipleri olarak

isim		alan		tur																Deger

bool		1byte		true/false -> 0/digerleri										0-istenilen say� i�in true
 
short		2byte		tamsayi															-32768 to 32767
int			4byte		tamsayi															-2milyar to +2milyar
long		8byte		tamsayi ->int dan daha buyuk									
unsigned short 2byte	tamsayi ->negatif degerleri almaz								0 to 65536
unsigned int  4byte		tamsayi ->negatif degerleri almaz								0 to +4milyar

float		4byte		ondal�kl� sayi													1.5*10^(-45) to 3.4*10^(38)
double		8byte		ondal�kl� sayi ->float a gore , ondal�k haznesi daha hassas.	art�k ben bile sayamad�m
string		8byte		yaz�															ciddi ciddi fazla karakter
char		2byte		tek karakter													tek 1 karakter al�r.


*/
#include<iostream>
using namespace std;
int main(){
	
 	 
 	 
 	 
	getchar();
	return 0;
	
}

/* 
	tip d�n���mlerinde dikkat edilmesi gerekilen kurallar
	
	1-) k�c�k bir veri tipinden b�y�k bir veri tipine aktar�mda sorun ya�anmaz 
		int sayi =0;
		short sayi2 = 1;
		sayi = sayi2			Basarili bir aktar�md�r
		
	2-) buyuk bir veri tipinden kucuk bir veri tipine aktar�m yap�l�rken veri kayb� ya�an�r
		float pi=3.14f;
		int deger= 0;
		deger = pi 		deger icerisinde 3 'u tutacaktir , geli�mi� dillerde derleyici hata/uyar� veirir bunu d�zeltmenin yolu kapal� tip d�n���m�d�r
		yani deger = (int)pi ;	ifadesi daha do�ru bir ifade olacakt�r.
		
	3-) islem yapilirken veri tipleri , isleme giren ifadelerin veri tiplerinin en buyugu olarak isleme al�n�r. yani
	
		cout<<(3/2) << endl		sonuc : 1		burada 3 ve 2 say�lar� int turunden oldugundan dolayu (default) islem sonucu int d�r.
		cout<<(3.0/2)<<enld		sonuc :1.5		burada 3.0 denildiginde , derleyici bunu otomatik olarak double alg�lar ,
												paydadaki 2 int degerindedir , bu da double degerine yukseltilir ve islem sonucu yap�l�r


*/
