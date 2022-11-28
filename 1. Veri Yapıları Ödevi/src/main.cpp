/*
* File: main.cpp
* Description:dosyaOkuma sınıfından dosya nesnesi ürettim ve kurucu fonksiyonuna veriler.txt dosyasını verdim,yoneticİlİSTESİ yonliste nesnesini olusturdum ve bu listeyi
yoneticiListesiDoldur() yardımıyla veriler ile doldurdum.ekranYazdir sınıfından yazdir nesnesi olusturdum ve kurucusuna yonliste yi verdim.Bu bize yazdırma olanagıgı saglayacak.
sonra ortalamayaGOreSirala() fonksiyonu yardımıyla ortalamaya göre sıraladım.do while yapısını kullandım programın en az bir kere calısmasını istedihim icin ve yoneticiListesiYazdir()
fonksiyonu ile yazdirma islemini yaptim.Bilgilendirme gectim.
ve c koşulları yazdım.
* Assignment: 1.Odev
* Date: 11:26:2022
* Author: Mert Umul
*/
#include <iostream>
using namespace std;
#include "yoneticiListesiDugum.hpp"
#include "yoneticiListesi.hpp"
#include "dosyaOkuma.hpp"
#include "ekranYazdir.hpp"
#include <cstdlib>

int main(int argc, char** argv)
{

    

    dosyaOkuma * dosya = new dosyaOkuma("veriler.txt");

    yoneticiListesi *yonliste = dosya->yoneticiListesiDoldur();
   ekranYazdir *yazdir = new ekranYazdir(yonliste);
    yonliste->ortalamayaGOreSirala();
    string karakter = "";
    do {

        yazdir->yoneticiListesiYazdir();
        cout<<"Bilgilendirme"<<endl;
        cout<<"Programdan cikmak icin q'ya basin"<<endl;
        cout<<"Onceki dugume gitmek icin z'ye basin"<<endl;
        cout<<"Sonraki dugume gitmek icin c'ye basin"<<endl;
        cout<<"8 dugum ileri gitmek icin d'ye basin"<<endl;
        cout<<"8 dugum geri gitmek icin a'ye basin"<<endl;
        cout<<"secili olan dugum  yonetici listesinden  cikarmak icin p'ye basin"<<endl;
        cout<<"secili olan dugume ait SatirListesi icerisinden rastgele bir dugum silmek icin iki defa k'ya basin"<<endl;





        cin>>karakter;
        if (karakter == "c") {
            yonler yon = yukari;
            yazdir->pozAyarla(yon);
        } else if (karakter == "z") {
            yonler yon = asagi;
            yazdir->pozAyarla(yon);
        } else if (karakter == "k") {
            int rastgeleIndeks = 0;
            try {
                rastgeleIndeks = yazdir->rastgeleSecilenDugumuGoster();
            } catch (...) {
                continue;

            }
            cin>>karakter;
            if (karakter == "k") {

                yazdir->rastgeleSecilenDugumuSil(rastgeleIndeks);
                yonliste->ortalamayaGOreSirala();

            }

        else if (karakter == "a") {
            yazdir->sayfaAyarla(altSayfa);
        }
        else if (karakter == "d") {
            yazdir->sayfaAyarla(ustSayfa);
        } 

        } else if (karakter == "p") {
            yazdir->yoneticiDugumSil();
        } 

    } while (karakter != "q");



    return 0;



   

}
