//Aciklama ekle
#include "siparis.h"
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include "fields.h"
#include "jrb.h"
#include "jval.h"


int Kontrol(int alanSayisi , char* katar)
{
	if(!strcmp(katar,"add") && alanSayisi == 5) return 1; 
	else if(!strcmp(katar,"search") && alanSayisi == 2) return 1; 
	else if(!strcmp(katar,"write") && alanSayisi == 2) return 1; 
	else if(!strcmp(katar,"print") && alanSayisi == 1) return 1;
	else return 0;
}

JRB AgacEkle(IS is,JRB b)
{
  	int i;
  	char* temp=(char*)malloc(sizeof(char)*MAXLEN*is->NF); // tum komutun gecici olarak tutulmasi icin
  	for(i=1; i<is->NF; i++)
  	{
    	strcat(temp,strdup(is->fields[i])); // komuttan itibaren text2 ye atildi
    	if(i+1!=is->NF)
    	strcat(temp,",");
  	}
  	(void) jrb_insert_int(b,atoi(is->fields[1]), new_jval_s(strdup(temp)));
	free(is->fields[i]);
	free(temp);
	printf("Veriniz Basariyla Eklendi.....\n\n");
  	return b;
}

char* AgacAra(JRB b,int index)
{
	b=jrb_find_int(b,index);
	if(b==NULL)
	{
		return NULL;
	}
	return jval_s(b->val);
}

void DosyayaYaz(JRB b,char* fname)
{
	int fd;
	JRB ptr;
	fd = open(fname,O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
	 	perror("fileOpenError");
	 	exit(1); 
	}
	
	jrb_traverse(ptr, b)
  	{
  		write(fd,jval_s(ptr->val), strlen(jval_s(ptr->val)));
  	}
	close(fd);
}

void EkranaYaz(JRB b)
{
	JRB ptr;
	jrb_traverse(ptr, b)
  	{
  		printf("%s\n",jval_s(ptr->val));
  	}
	printf("\n");
}

JRB RedirectOku(char* dosya,JRB b)
{
	// Dosyayi islemleri
	IS is;
  	is = new_inputstruct(dosya);
  	if (is == NULL)
  	{
   	 	perror("Hata");
    	exit(1);
  	}
  	
	char *kelime = NULL;
	char *virgul = ",";
  
	int x;
	while(get_line(is) >= 0)
  	{
		x=1;
		kelime = strtok(is->text1,virgul);
		while(kelime!=NULL)
		{
			is->fields[x++] = kelime;                     
     		kelime=strtok(NULL,virgul);	     
		}
		is->NF = --x;
  		b = AgacEkle(is,b);
  	}	
  	jettison_inputstruct(is);
	return b;
}

void HeapTemizle(JRB root,IS is)
{
	jrb_free_tree(root);
	jettison_inputstruct(is);
	root=NULL;
	is=NULL;
}



