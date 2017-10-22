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
    class Program
    {
        static void Main(string[] args)
        {
            string ifade;
            string devam="e";

            while (devam != "h")
            {
                Console.Write("DFA icin ifade giriniz :");
                ifade = Console.ReadLine();
                DFA deneme = new DFA(ifade.ToLower());
                deneme.Calistir();

                Console.Write("Tekrar denemek ister misiniz ... :");
                devam = Console.ReadLine();
                if (devam.ToLower() == "e" || devam.ToLower() == "evet") devam = devam.ToLower();
                else devam = "h";

                Console.Clear();
            }
            Console.WriteLine("Prosedur basari ile sonlandirildi ...");
        }
    }
}
