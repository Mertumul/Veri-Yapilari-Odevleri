
#ifndef yoneticiListesiDugum_hpp
#define yoneticiListesiDugum_hpp
#include "satirListesi.hpp"

class yoneticiDugum
{
    public:
    double ortalama;
    yoneticiDugum *onceki;
    yoneticiDugum *sonraki;
    satirListesi *veri;
    double ortalamaHesapla();

    yoneticiDugum(satirListesi *veri);
    yoneticiDugum(satirListesi *veri, yoneticiDugum *sonraki);
    yoneticiDugum(satirListesi *veri, yoneticiDugum *sonraki, yoneticiDugum *onceki);
};
    

#endif