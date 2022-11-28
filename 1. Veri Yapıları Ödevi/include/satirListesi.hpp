#ifndef satirListesi_hpp
#define satirListesi_hpp
#include <iostream>
#include "satirListesiDugum.hpp"

class satirListesi
{
public:
    satirListesi();
    int boyutBul() const;
    bool bosMU() const;
    void ekle(const int &item);
    void arayaEkle(int index, const int &item);
    int itemYer(const int &item);
    void sil(const int &item);
    void aradanSil(int index);
    bool bul(const int &item);
    const int &dugumGetir(int index);
    void temizle();
    void printSatirListesi(int x, int y);

    friend ostream &operator<<(ostream &os, satirListesi &rgt);
    ~satirListesi();

private:
    satirListesiDugum *ilk;
    int boyut;
    satirListesiDugum *FindPreviousByPosition(int index);
};

#endif