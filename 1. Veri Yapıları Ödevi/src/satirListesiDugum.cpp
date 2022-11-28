/*
* File: satirListesiDugum.hpp
* Description:Burada bir ader satirListesiDugum sınıfı tanımladım ve sınıfa ait iki adet satirListesi türünden veri tanımladım onceki ve sonraki listenin adresini
 tutması icin ve bir adet integer veri türünden veri tanımladım  dugumun degerini tutabilmesi icin ve kurucu fonksiyonlar icin fonksiyon tanimladim.Bu kurucu fonksiyonlar
 gelen parametreyi satirListesi dugumune kaydediyor.
* Assignment: 1.Odev
* Date: 11:12:2022
* Author: Mert Umul
*/


#include "satirListesiDugum.hpp"

satirListesiDugum::satirListesiDugum(const int veri, satirListesiDugum *sonraki, satirListesiDugum *onceki)
{
    this->veri = veri;
    this->sonraki = sonraki;
    this->onceki = onceki;
}
satirListesiDugum::satirListesiDugum(const int veri, satirListesiDugum *sonraki)
{
    this->veri = veri;
    this->sonraki = sonraki;
    this->onceki = onceki;
}
satirListesiDugum::satirListesiDugum(const int veri)
{
    this->veri = veri;
    this->sonraki = sonraki;
    this->onceki = onceki;

}