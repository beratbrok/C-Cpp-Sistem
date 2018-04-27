#include <stdio.h>
#include "siparis.h"
#include <stdlib.h>
#include <string.h>

int main(int argc,char** argv)
{
	printf("\n***********Sistem Programlama Proje**********\n");
	IS is;
	JRB b;
	is = new_inputstruct(NULL); // Komut icin struct olustur
	b = make_jrb();  // Agac olustur
		
	if (is == NULL) 
	{
	  		exit(1);
	}
	//Komutlarin kontrol edilmesi
	if(argc >=2){
		RedirectOku(argv[1],b);
	}

	while(get_line(is) >= 0)
	{
		if(!strcmp(is->fields[0],"add"))
		{	
			if(Kontrol(is->NF,"add"))
	  		{
	  			b=AgacEkle(is,b);
	  		}	
			else
			{
				printf("Komut Bicim Hatasi\n");
				printf("Tavsiye : add|-sipKey-|-sipAd-|-SipMalzeme-|-sipRenk-\n");
			}
	  	}
	  	else if(!strcmp(is->fields[0],"search"))
	  	{
			if(Kontrol(is->NF,"search"))
			{
	  			char* temp;
	  			temp=AgacAra(b,atoi(is->fields[1]));
	  			if(temp==NULL)
	  			{
	  				printf("Boyle Bir Veri Bulunmamaktadir\n");
	  			}
	  			else
	  			{
	  				printf("%s\n",temp);
	  			}
			}
			else
			{
				printf("Komut Bicim Hatasi\n");
				printf("Tavsiye : search|-sipKey-\n");
			}
	  	}
	  	else if(!strcmp(is->fields[0],"write"))
	  	{
			if(Kontrol(is->NF,"write"))
			{
	  			DosyayaYaz(b,is->fields[1]);
			}
			else
			{
				printf("Komut Bicim Hatasi\n");
				printf("Tavsiye : write|-FileName-\n");
			}
	  	}
	  	else if(!strcmp(is->fields[0],"print"))
		{	
			if(Kontrol(is->NF,"print"))
			{
	  			EkranaYaz(b);
			}
			else
			{
				printf("Komut Bicim Hatasi\n");
				printf("Tavsiye : print");			
			}
	  	}
		else{
			printf("Komut Giris Hatasi...\n");
		}
				
	  }
	  HeapTemizle(b,is);
 	return 0;
}
