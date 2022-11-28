/*
* File: yoneticiListesiDugum.cpp
* Description:Burada satirListelerini tutacak yonetici node olusturdum.Bir adet double ortalama degiskeni var bu satır listesindeki dugumlerin ortralamasını turması icin 
yonetici dugum türünden onceki ve sonraki degiskenlerim var bunlar yonetici dugumlerinin ondan onceki ve sonraki degiskenlerini tutuyor.Bir adet satirListesi türünden veri 
degiskenim var bu da o yönetici dugumune ait olan satir listesini gösteriyor bu sayede ic ice baglıliste yapmıs oluyoruz.Double ortalamaHesapla fonksiyonumuz var bu da
o satir listesine baglı olan satirListesi dugumlerinin verilerini toplayıp ortalamasını alıyor.Son olarak ta 3 adet kurucu fonksiyonumuz var.

* Assignment: 1.Odev
* Date: 11:16:2022
* Author: Mert Umul
*/


#include "yoneticiListesiDugum.hpp"

yoneticiDugum::yoneticiDugum(satirListesi *veri)
{
    this->veri = veri;
    this->onceki = onceki;
    this->sonraki = sonraki;
    this->ortalama = ortalamaHesapla();
}
yoneticiDugum::yoneticiDugum(satirListesi *veri, yoneticiDugum *sonraki)
{
    this->veri = veri;
    this->onceki = onceki;
    this->sonraki = sonraki;
    this->ortalama = ortalamaHesapla();
}
yoneticiDugum::yoneticiDugum(satirListesi *veri, yoneticiDugum *sonraki, yoneticiDugum *onceki)
{
    this->veri = veri;
    this->onceki = onceki;
    this->sonraki = sonraki;
    this->ortalama = ortalamaHesapla();
}

double yoneticiDugum::ortalamaHesapla()
{
    double toplam = 0;
    if (this->veri->bosMU())
        return toplam;
    int boyut = this->veri->boyutBul();
    for (int i = 0; i < boyut; ++i)
        toplam += this->veri->dugumGetir(i);
    return toplam / boyut;
}