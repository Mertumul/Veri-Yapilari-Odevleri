#ifndef kontrol_hpp
#define kontrol_hpp

#include <iostream>
#include "organ.hpp"
#include "sistem.hpp"

class Kontrol
{
private:
    int dosyaSat;
    std::string dosyAdi = "Veri.txt";
    int organSayisi;
    int sistemSayisi;

public:
    Kontrol();
    Organ *organ;
    Sistem *sistem;
    int kacSatir();
    void veri_Oku();
    void veriOku(int organIndeks);
};

#endif