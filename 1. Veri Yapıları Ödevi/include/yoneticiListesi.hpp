

#ifndef yoneticiListesi_hpp
#define yoneticiListesi_hpp

#include "satirListesi.hpp"
#include "yoneticiListesiDugum.hpp"
#include <stdlib.h>
#include <time.h>
#include <iostream>


class yoneticiListesi
{
private:
    int boyut;
    yoneticiDugum *FindPreviousByPosition(int sira);
    yoneticiDugum * FindPosition(int sira);
    yoneticiDugum *ilk;


public:
    yoneticiListesi();
    int boyutBul() const;
    bool bosMU() const;
    bool bul(satirListesi *&veri);
    void ekle(satirListesi *&veri);
    void arayaEkle(int sira, satirListesi *&veri);
    int itemYer(satirListesi *&veri);
    void sil(satirListesi *&veri);
    void aradanSil(int sira);
    void rastgeleSatirListesindenSil(int sira, int icsira);
    void ortalamaHesapla(int sira);
    int rastgeleUretici(int sira);
    void dugumTasi(int from, int to);
    void ortalamayaGOreSirala();
    satirListesi *&dugumGetir(int sira);
    void temizle();
    void printIndex(int index, int x, int y);

    ~yoneticiListesi();
};

#endif