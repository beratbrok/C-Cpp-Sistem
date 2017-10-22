/* 
        BİÇİMSEL DİLLER VE SOYUT MAKİNELER DERSİ 2. ÖDEV DFA PROGRAMI 

 AD     : Osman
 Soyad  : Yasal
 NO     : B-151-210-083
 OKUL   : Sakarya ÜNİVERSİTESİ
 BÖLÜM  : Bilgisayar Mühendisliği
 SINIF  : 3
 DÖNEM  : 1
 
 
 
 */
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Biçimsel_diller_ödev__2
{
    class DFA
    {
        int durum;
        int[] kabul_durumlari;
        string katar;
        bool sonuc;


        public DFA(string katar)
        {
            this.katar = katar;
            kabul_durumlari = new int[] {3 , 4};
            sonuc = true;
            durum = 0;
        }

        public void Calistir()
        {
            while(katar != "")
            {
                if (katar.Length >= 2)  // katar uzunlugu cok fazlaysa buradan yapilir
                {
                    // her bir durum için a gelince nereye gidecegi belirtilmistir

                    if (katar[0] == 'a' && durum == 0) { durum = 1; katar = katar.Substring(1); }
                    else if (katar[0] == 'a' && durum == 1) { durum = 3; katar = katar.Substring(1); }
                    else if (katar[0] == 'a' && durum == 2) { durum = 1; katar = katar.Substring(1); }
                    else if (katar[0] == 'a' && durum == 3) { durum = 5; sonuc = false; break; }     // çöp durumunda direk bitir
                    else if (katar[0] == 'a' && durum == 4) { durum = 3; katar = katar.Substring(1); }


                    //  her bir durum için b gelince nereye gidecegi belirtilmistir
                    else if (katar[0] == 'b' && durum == 0) { durum = 2; katar = katar.Substring(1); }
                    else if (katar[0] == 'b' && durum == 1) { durum = 2; katar = katar.Substring(1); }
                    else if (katar[0] == 'b' && durum == 2) { durum = 4; katar = katar.Substring(1); }
                    else if (katar[0] == 'b' && durum == 3) { durum = 4; katar = katar.Substring(1); }
                    else if (katar[0] == 'b' && durum == 4) { durum = 5; sonuc = false; break; } // çöp durumunda direk bitir

                    else           // girilen ifade a veya b den baska bir ifadeyse kabul etme
                    {
                        durum = -1;             
                        sonuc = false;
                        break;
                    }
                }
                else if(katar.Length < 2)   // tek karakter girilmesi durumunda (substring(1) tek karakter icin calismayacaktir. o yuzden bunu yaptim)
                {

                    if (katar[0] == 'a' && durum == 0) { durum = 1; katar = ""; }
                    else if (katar[0] == 'a' && durum == 1) { durum = 3; katar = ""; }
                    else if (katar[0] == 'a' && durum == 2) { durum = 1; katar = ""; }
                    else if (katar[0] == 'a' && durum == 3) { durum = 5; sonuc = false; break; }     // çöp durumunda direk bitir
                    else if (katar[0] == 'a' && durum == 4) { durum = 3; katar = ""; }


                    // b gelmesi durumları ...
                    else if (katar[0] == 'b' && durum == 0) { durum = 2; katar = ""; }
                    else if (katar[0] == 'b' && durum == 1) { durum = 2; katar = ""; }
                    else if (katar[0] == 'b' && durum == 2) { durum = 4; katar = ""; }
                    else if (katar[0] == 'b' && durum == 3) { durum = 4; katar = ""; }
                    else if (katar[0] == 'b' && durum == 4) { durum = 5; sonuc = false; break; } // çöp durumunda direk bitir

                    else           // girilen ifade a veya b den baska bir ifadeyse kabul etme
                    {
                        durum = -1;
                        sonuc = false;
                        break;
                    }
                }

            }

            // son durum bizim kabul durumlarimiz icersinde yer aliyorsa , bu katari kabul et aksi halde kabul etme.
            if (durum == kabul_durumlari[0] || durum == kabul_durumlari[1]) sonuc = true;
            else sonuc = false;


            Console.WriteLine("Tanınma durumu ... : " + sonuc);


        }




    }
}
