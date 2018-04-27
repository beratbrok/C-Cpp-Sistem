#ifndef SIPARIS_H
#define SIPARIS_H
#include "jrb.h"
#include "fields.h"

JRB AgacEkle(IS,JRB);
char* AgacAra(JRB,int);
void DosyayaYaz(JRB,char*);
void EkranaYaz(JRB);
JRB RedirectOku(char*,JRB);
int Kontrol(int , char*);
void HeapTemizle(JRB,IS);
#endif
