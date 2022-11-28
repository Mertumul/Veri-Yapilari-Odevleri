


#ifndef ekranYazdir_hpp
#define ekranYazdir_hpp

#include "yoneticiListesi.hpp"
#include "ekranYer.hpp"

#define satirSinir 8
#define satirBaslangic 0

enum yonler {
    yukari = 0,
    asagi = 1,
    yenile = 2,

};

enum sayfaYonu {
    ustSayfa = 0,
    altSayfa = 1,
};

class ekranYazdir {
private:
    yoneticiListesi *yonetici;
    int poz;
    int baslangicPoz;
    int bitisPoz;

    void pozAyarla();
public:

    void pozAyarla(yonler yn);
    void sayfaAyarla(sayfaYonu syn);
    
    void yoneticiDugumSil();

    void rastgeleSecilenDugumuSil(int rastgeleIndeks);

    void yoneticiListesiYazdir();

    void secilenSatirListesiYazdir(int x, int y);


    ekranYazdir(yoneticiListesi* yonetici);

 

    int rastgeleSecilenDugumuGoster();

};

#endif 
