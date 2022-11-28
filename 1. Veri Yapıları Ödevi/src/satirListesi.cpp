/*
* File: satirListesi.hpp
* Description:satirListesiDugumleri yonetsin diye bir satirListesi sınıfı tanımladım.Bu sınıfta bir adet kurucu fonksiyon bulunmaktadır bu kurucu satir listesinin
 boyutuna  0 vermektedir ilk degerinede NUll degerini atamaktadır  cunku liste olusturuldugunda boyutu 0 bir yeri de göstememesi gerekir,boyutBul() fonksiyonu satırListesiDugum 
 sayısını getirmektedir.bosMu fonksiyonu satirListesi Dugumunun bos olup olmadıgını kontrol ediyor. ekle() fonksiyonu dugumun sonuna yeni dugum ekliyor. arayaEkle() 
 fonksiyonu dugum.un arasına istedigin yere eleman eklettiriyor.sil() fonksiyonu dugumun sonundan eleman siliyor.aradanSil() fonksiyonu dugumun arasından istedigin sıradaki 
 dugumu siliyor.bul() fonksiyonu istenilen verininin listede olup olmadıgına bakıyor varsa true yoksa false döndürüyor.dugumGetir() fonksiyonu istenilen siradaki 
 dugumu getiriyo,temizle() fonksiyonu teker teker tüm dugumleri siliyor,printSatirListesi() fonksiyonu kordinat yerine göre onceki adres,veri ve sonraki adresi 
 yazdırmak icin kullandım ayrıca cerceveyi de burada cizdirdim. Private olarak bir tane head tanımladım bu ilk dugumu gösteriyor, boyut degiskeni tanımladım bu da kac tane 
 dugum oldugunu tutuyor ekleme isleminde artarken silme isleminde boyut azalır.Bir adet de FindPreviousByPosition() fonksiyonu var bu da istenilen dugumden 
 bir onceki dugumu getiriyor.
* @Course:1.Ogretim Bgrubeu
* Assignment: 1.Odev
* Date: 11:16:2022
* Author: Mert Umul
*/

#include "satirListesi.hpp"
#include <iomanip>
#include "ekranYer.hpp"

satirListesi::satirListesi()
{
    boyut = 0;
    ilk = NULL;
}

int satirListesi::boyutBul() const
{
    return boyut;
}
bool satirListesi::bosMU() const
{
    return boyut == 0;
}

void satirListesi::ekle(const int &item)
{
    arayaEkle(boyut, item);
}
void satirListesi::arayaEkle(int index, const int &item)
{
    if (index < 0 || index > boyut)
        throw "Index out of Range";
    if (index == 0)
    {
        ilk = new satirListesiDugum(item, ilk);
        if (ilk->sonraki != NULL)
            ilk->sonraki->onceki = ilk;
    }
    else
    {
        satirListesiDugum *prv = FindPreviousByPosition(index);
        prv->sonraki = new satirListesiDugum(item, prv->sonraki, prv);
        if (prv->sonraki->sonraki != NULL)
            prv->sonraki->sonraki->onceki = prv->sonraki;
    }
    boyut++;
}

bool satirListesi::bul(const int &item)
{
    for (satirListesiDugum *itr = ilk; itr != NULL; itr = itr->sonraki)
    {
        if (itr->veri == item)
            return true;
    }
    return false;
}

int satirListesi::itemYer(const int &item)
{
    int index = 0;
    for (satirListesiDugum *itr = ilk; itr != NULL; itr = itr->sonraki)
    {
        if (itr->veri == item)
            return index;
        index++;
    }
    return 0;
}
void satirListesi::sil(const int &item)
{
    int index = itemYer(item);
    aradanSil(index);
}

void satirListesi::aradanSil(int index)
{
    if (index < 0 || index >= boyut)
        throw "Index out of Range";
    satirListesiDugum *del;
    if (index == 0)
    {
        del = ilk;
        ilk = ilk->sonraki;
        if (ilk != NULL)
            ilk->onceki = NULL;
    }
    else
    {
        satirListesiDugum *prv = FindPreviousByPosition(index);
        del = prv->sonraki;
        prv->sonraki = del->sonraki;
        if (del->sonraki != NULL)
            del->sonraki->onceki = prv;
    }
    boyut--;
    delete del;
}

const int &satirListesi::dugumGetir(int index)
{
    if (index < 0 || index >= boyut)
        cout << "No Such Element";
    if (index == 0)
        return ilk->veri;
    return FindPreviousByPosition(index)->sonraki->veri;
}



void satirListesi::temizle()
{
    while (!bosMU())
        aradanSil(0);
}

ostream &operator<<(ostream &os, satirListesi &rgt)
{

    for (satirListesiDugum *itr = rgt.ilk; itr != NULL; itr = itr->sonraki)
    {
        os << itr << "\n";
        os << "-----------\n";
        os << "|" << setw(5) << itr->veri << setw(5) << "|" << endl;
        os << "-----------\n";
        os << "|" << itr->sonraki << setw(3) << "|\n";
        os << "-----------\n\n";
    }
    os << endl;
    return os;
}
void satirListesi::printSatirListesi(int x,int y){
    int yIndex=y; 
    ekranYer.gotoxy(x,yIndex);
    cout<<"vvvvvvvv\n"; 
     for (satirListesiDugum *itr = this->ilk; itr != NULL; itr = itr->sonraki) {
      
        ekranYer.gotoxy(x,++yIndex);
        cout<<itr<<"\n";
        
        ekranYer.gotoxy(x,++yIndex);
        cout<<"-----------\n";
        ekranYer.gotoxy(x,++yIndex);
        cout<<"|"<<setw(5)<<itr->veri<<setw(5)<<"|"<<endl;
        ekranYer.gotoxy(x,++yIndex);
        cout<<"-----------\n";
        ekranYer.gotoxy(x,++yIndex);
        cout<<"|"<<itr->sonraki<<setw(3)<<"|\n";
        ekranYer.gotoxy(x,++yIndex);
        cout<<"-----------\n\n";
    }
}

satirListesiDugum *satirListesi::FindPreviousByPosition(int index)
{
    if (index < 0 || index > boyut)
        cout << "Boyle bir eleman yok";
    satirListesiDugum *prv = ilk;
    int i = 1;
    for (satirListesiDugum *itr = ilk; itr->sonraki != NULL && i != index; itr = itr->sonraki, i++)
    {
        prv = prv->sonraki;
    }
    return prv;
}

satirListesi::~satirListesi()
{
    temizle();
}