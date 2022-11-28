#ifndef dosyaOkuma_hpp
#define dosyaOkuma_hpp
#include "yoneticiListesi.hpp"
#include "satirListesi.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

class dosyaOkuma{
public:
    dosyaOkuma(string);
    string dosyaAdi;
    satirListesi**satir;
    int satirSayisi();
    void satirOku();
    yoneticiListesi*yoneticiListesiDoldur();
    ~dosyaOkuma();



};



#endif