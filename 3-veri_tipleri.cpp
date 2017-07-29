/*

temel veri tipleri olarak

isim		alan		tur																Deger

bool		1byte		true/false -> 0/digerleri										0-istenilen sayý için true
 
short		2byte		tamsayi															-32768 to 32767
int			4byte		tamsayi															-2milyar to +2milyar
long		8byte		tamsayi ->int dan daha buyuk									
unsigned short 2byte	tamsayi ->negatif degerleri almaz								0 to 65536
unsigned int  4byte		tamsayi ->negatif degerleri almaz								0 to +4milyar

float		4byte		ondalýklý sayi													1.5*10^(-45) to 3.4*10^(38)
double		8byte		ondalýklý sayi ->float a gore , ondalýk haznesi daha hassas.	artýk ben bile sayamadým
string		8byte		yazý															ciddi ciddi fazla karakter
char		2byte		tek karakter													tek 1 karakter alýr.


*/
#include<iostream>
using namespace std;
int main(){
	
 	 
 	 
 	 
	getchar();
	return 0;
	
}

/* 
	tip dönüþümlerinde dikkat edilmesi gerekilen kurallar
	
	1-) kücük bir veri tipinden büyük bir veri tipine aktarýmda sorun yaþanmaz 
		int sayi =0;
		short sayi2 = 1;
		sayi = sayi2			Basarili bir aktarýmdýr
		
	2-) buyuk bir veri tipinden kucuk bir veri tipine aktarým yapýlýrken veri kaybý yaþanýr
		float pi=3.14f;
		int deger= 0;
		deger = pi 		deger icerisinde 3 'u tutacaktir , geliþmiþ dillerde derleyici hata/uyarý veirir bunu düzeltmenin yolu kapalý tip dönüþümüdür
		yani deger = (int)pi ;	ifadesi daha doðru bir ifade olacaktýr.
		
	3-) islem yapilirken veri tipleri , isleme giren ifadelerin veri tiplerinin en buyugu olarak isleme alýnýr. yani
	
		cout<<(3/2) << endl		sonuc : 1		burada 3 ve 2 sayýlarý int turunden oldugundan dolayu (default) islem sonucu int dýr.
		cout<<(3.0/2)<<enld		sonuc :1.5		burada 3.0 denildiginde , derleyici bunu otomatik olarak double algýlar ,
												paydadaki 2 int degerindedir , bu da double degerine yukseltilir ve islem sonucu yapýlýr


*/
