/*
* File: ekranYazdirma.cpp
* Description:satirSinirını 8 tanımladım bizden 8tek sefer 8 dugum yoneticidugumu gostermemizi istediginiz icin,satirBaslangici 0 tanimladim 0 dan baslayacagiz.ekranYazdir()
fonksiyonu yoneticiListesine göre bitispozisyonu ve baslangıc pozisyonunu ayarlıyor,sayfaAyarla() foksiyonu gecme islemi icin sayfayı yeni pozisyonu sokmak icin kullandım 
8 sınırına geldiginde diger sayfayı ayarlamak icin,pozAyarla() fonsksiyonuyla verilen paremetreye göre ileri veya önceki dügüme gecmek icin kullandım.yoneticiListesiYazdir()
fonksiyonu her cagrıldıgında ekranı cls komutu yardımıyla temizler ,yonetici listesi bos ise goruntulencek yonetici listesi yok ,baslangıc pozisyonu sıfır ise ilk degilse geri 
okları cıkıyor, bitispozisyonu yoneticilistesi boyutuna esitse son oku degilse ileri oku cıkıyor, en sonunda yonetici dugumunlerini ve secilen satirListesini yazdir 
yardımıyla secilen satir listesini yazdiriyor.rastgeleSecilenDugumuGoster()  o yonetici dugumunu ait rastge satirListesi dugumunu gösterir ve gösterilen dugumde 
silinecek yazar.yoneticiDugumSil() fonksiyonunu yonetici dugumunu siler.main.cpp de rasgele sectigimiz dugumle birlikte kullanılarak o dugumu silmek icin rastgeleSecilenDugumuSil() 
fonksiyonu kullandım.


* Assignment: 1.Odev
* Date: 11:25:2022
* Author: Mert Umul
*/

#include "ekranYazdir.hpp"

ekranYazdir::ekranYazdir(yoneticiListesi* yonetici) {
    this->yonetici = yonetici;
    if (this->yonetici->boyutBul() < satirSinir) {
        this->bitisPoz = this->yonetici->boyutBul();
    } else {
        this->bitisPoz = satirSinir;
    }

    this->baslangicPoz = satirBaslangic;

}

void ekranYazdir::pozAyarla() {
    int page = poz / satirSinir;
    this->baslangicPoz = satirSinir*page;
    this->bitisPoz = satirSinir * (page + 1);
    if (this->bitisPoz >= this->yonetici->boyutBul()) {
        this->bitisPoz = this->yonetici->boyutBul();

    }
}

void ekranYazdir::pozAyarla(yonler yn) {

    if (yn == yukari) {
        if (poz >= this->yonetici->boyutBul() - 1) {
            return;
        }
        ++poz;
        pozAyarla();
    } else if (yn == asagi) {
        if (poz <= 0) {

            return;
        }
        --poz;
        pozAyarla();
    } else if (yn == yenile) {
        pozAyarla();
    }

}

void ekranYazdir::sayfaAyarla(sayfaYonu syn) {
    if (syn == altSayfa) {
        for (int i = 0; i < satirSinir; ++i) {
            this->pozAyarla(asagi);
        }
    } else if (syn == ustSayfa) {
        for (int i = 0; i < satirSinir; ++i) {
            this->pozAyarla(yukari);
        }
    }
}

void ekranYazdir::yoneticiListesiYazdir() {

    int count = yonetici->boyutBul();
    system("cls");
    if (count == 0) {
        cout << "Goruntulenecek bir Yonetici listesi yok\n";
        exit(1);
        return;
    }


    ekranYer.gotoxy(0, 0);
    if (this->baslangicPoz == 0) {
        cout << "<--ilk--";
    } else {
        cout << "<---geri--";
    }


    int showingNodeCount = this->bitisPoz - this->baslangicPoz;
    showingNodeCount *= 13;


    ekranYer.gotoxy(showingNodeCount, 0);


    if (this->bitisPoz == yonetici->boyutBul()) {
        cout << "--son-->";
    } else {
        cout << "--ileri-->";
    }
    for (int i = this->baslangicPoz; i<this->bitisPoz; ++i) {


        int mod = i % satirSinir;
        this->yonetici->printIndex(i, 15 * mod, 1);

    }
    this->secilenSatirListesiYazdir((this->poz % satirSinir) *15, 9);
}

 void ekranYazdir::secilenSatirListesiYazdir(int x, int y) {
        this->yonetici->dugumGetir(this->poz)->printSatirListesi(x, y);

    }
  int ekranYazdir::rastgeleSecilenDugumuGoster() {

        int randomSelected = this->yonetici->rastgeleUretici(this->poz);
        int xPosition = ((this->poz % satirSinir) + 1)*15;
        int yPosition = (randomSelected)*6;
        yPosition += 12;
        ekranYer.gotoxy(xPosition, yPosition);
        cout << "<--silinecek";
        yPosition = this->yonetici->dugumGetir(this->poz)->boyutBul()*6 + 12;

        ekranYer.gotoxy(0, yPosition - 1);


        return randomSelected;

    }
  void ekranYazdir::yoneticiDugumSil() {
        this->yonetici->aradanSil(this->poz);
       this->pozAyarla(yenile);
      
        if(this->poz==this->bitisPoz){
            this->poz--;
        }
         this->pozAyarla(yenile);

   

    }
  void ekranYazdir::rastgeleSecilenDugumuSil(int randomIndeks) {
        this->yonetici->rastgeleSatirListesindenSil(this->poz, randomIndeks);
    }