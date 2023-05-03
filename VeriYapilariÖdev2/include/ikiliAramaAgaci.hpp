#ifndef ikiliAramaAgaci_hpp
#define ikiliAramaAgaci_hpp

#include "queue.hpp"

class Dugum
{
public:
    Dugum();
    int yukseklik;
    int veri;
    Queue dnaSatiri;
    Dugum *sol;
    Dugum *sag;
};

class IAA
{
public:
    IAA();
    ~IAA();
    int *arrm;
    int index;
    Queue *veriCek;
    Dugum *dugum = nullptr;
    int yukseklikGetir(Dugum *kok);
    int dengeDegerGetir(Dugum *kok);
    int denge(Dugum *kok);
    void postOrder(Dugum *kok);
    void mutasyon(Dugum *kok);
    Dugum *ekle(Dugum *kok, int new_Data, Queue mData);
};

#endif