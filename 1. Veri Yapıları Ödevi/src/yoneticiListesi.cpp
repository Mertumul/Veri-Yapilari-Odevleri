/*
* File: yoneticiListesi.cpp
* Description:Burada yonetici dugumleri yonetmek icin yoneticiListesi sınıfı olusturdum.Private olarak boyut degiskenim var bu yonetici dugumlerinin boyutunu tutuyor.
yoneticiDugum cinsinden üc tane fonksiyonum var FindPreviousByPosition() fonksiyonu yonetici dugumunden istenilen dugumden bir onceki dugumu getiriyor, FindPosition() ise
istenilen siradaki dugumu getiriyor ve  ilk degsikenide yonetici dugumunun basını(ilk degerini) tutuyor.Publicte ise bie adet kurucu fonksiyonumuz ve bir adet yıkıcı 
fonksiyonumuz bulunmaktadır,boyutBul() fonksiyonu yonetici dugumlerinin saysısı getir,BosMu() fonksiyonu yonetici dugumumu bos mu degil mi onu kontrol eder,bul() fonksiyonu
istenilen satirListesi verisi var mı onu konrol eder,ekle() fonksiyonu yonetici dügümü olusturur ve verilen satir listesini o dugume ekler,arayaEkle() fonksiyonu istenilen 
pozisyonda bir yonetici dugum olusturur ve o dugume verilen satirListesi ekler.itemYer fonksiyonu yonetici dugumlerinde gezerek istenilen satirListesi verisini arar bulursa
o nerede oldugun sirasini gönderir,sil() fonksiyonu yonetici dugum listesinin sonundaki dugumu siler,aradanSil() fonksiyonu ise istenilen yerdegi yonetici dugumu siler,
rastgeleSatirListesindenSil() fonksiyonu rastgele satir listesinden bir dugum siliyor,dugumTasi() fonksiyonu iki paremetre alıyor ve  bu paremete dugumun nereden 
nereye tasınacagını gösteriyor ve tasıma islemini yapıyor,ortalamayaGöreSırala fonksiyonu yonetici dugumundeki ortalamaya göre sıralama islemini yapıyor mantık ise dugumu 
secıyor obur ortalamadan buyuk mu kucuk mu diye bakıyor eger büyükse büyük olanı bir saga kaydırıyor dugum tası fonksiyonu ile bunu yonetici dugumu bitene kadar yapıyorlar,
dugumGetir() fonksiyonu ise verdigimiz paremetreye gore satirListesindeki dugumu getiriyor,temizle() fonksiyonu teker teker tüm dugumleri siliyor bosMu() ve aradanSil()
fonksiyonları yardımıyla eger bos degilse dugum birinci elemanı sil bu bitene kadar gidecek,printIndex fonksiyonu ise yoneticiListesi dugumun elemanlarını yazdırma fonksiyonudur,
goto ve kordinat sistemini kullanarak nereye yazılacagını halleder.

* Assignment: 1.Odev
* Date: 11:17:2022
* Author: Mert Umul
*/



#include"yoneticiListesi.hpp"
#include<iostream>
#include<iomanip>
#include "ekranYazdir.hpp"
#include <string>
yoneticiDugum* yoneticiListesi::FindPreviousByPosition(int sira) {
    if (sira < 0 || sira > boyut) throw("hata!!");
        
    yoneticiDugum *prv = ilk;
    int i = 1;
    for (yoneticiDugum *itr = ilk; itr->sonraki != NULL && i != sira; itr = itr->sonraki, i++) {
        prv = prv->sonraki;
    }
    return prv;
}


yoneticiDugum* yoneticiListesi::FindPosition(int sira) {
    if (sira < 0 || sira >= boyut) throw("Boyle bir eleman yok");
       
    return this->FindPreviousByPosition(sira + 1);

}
satirListesi*& yoneticiListesi::dugumGetir(int sira) {
    if (sira < 0 || sira >= boyut) throw("Hata!!!");
  
    if (sira == 0) return ilk->veri;
    return FindPreviousByPosition(sira)->sonraki->veri;
}

yoneticiListesi::yoneticiListesi(){
    ilk=NULL;
    boyut=0;
}

int yoneticiListesi::boyutBul()const{
    return boyut;
    
}

bool yoneticiListesi::bosMU()const {
    return boyut == 0;
}
bool yoneticiListesi::bul(satirListesi*& veri) {
    for (yoneticiDugum *itr = ilk; itr != NULL; itr = itr->sonraki) {
        if (itr->veri == veri) return true;
    }
    return false;
}

void yoneticiListesi::ekle(satirListesi*& veri) {
    arayaEkle(boyut, veri);
}

void yoneticiListesi::arayaEkle(int sira, satirListesi*& veri) {
    if (sira < 0 || sira > boyut) 
        cout<<"Gecersiz Indeks";
    if (sira == 0) {
        ilk = new yoneticiDugum(veri, ilk);
        if (ilk->sonraki != NULL) ilk->sonraki->onceki = ilk;
    } else {
        yoneticiDugum *prv = FindPreviousByPosition(sira);
        prv->sonraki = new yoneticiDugum(veri, prv->sonraki, prv);
        if (prv->sonraki->sonraki != NULL)
            prv->sonraki->sonraki->onceki = prv->sonraki;
    }
    boyut++;
}

int yoneticiListesi::itemYer(satirListesi*& veri) {
    int sira = 0;
    for (yoneticiDugum *itr = ilk; itr != NULL; itr = itr->sonraki) {
        if (itr->veri == veri) return sira;
        sira++;
    }
    cout<<"Boyle bir eleman yok";
    return 0;
}

void yoneticiListesi::sil(satirListesi*& veri) {
    int sira = itemYer(veri);
    aradanSil(sira);
}
void yoneticiListesi::aradanSil(int sira) {
    if (sira < 0 || sira >= boyut) 
        cout<<"Gecersiz Indeks";
    yoneticiDugum *silinecek;
    if (sira == 0) {
        silinecek = ilk;
        ilk = ilk->sonraki;
        if (ilk != NULL) ilk->onceki = NULL;
    } else {
        yoneticiDugum *prv = FindPreviousByPosition(sira);
        silinecek = prv->sonraki;
        prv->sonraki = silinecek->sonraki;
        if (silinecek->sonraki != NULL)
            silinecek->sonraki->onceki = prv;
    }
    boyut--;
    delete silinecek;
}

void yoneticiListesi::rastgeleSatirListesindenSil(int sira, int icsira){

    int sayim = this->boyutBul();
    if (sira < 0 || sira >= sayim)
        cout<<"Gecersiz Indeks";

    satirListesi* SatirListesi = this->dugumGetir(sira);

    SatirListesi->aradanSil(icsira);
    ortalamaHesapla(sira);
}

void yoneticiListesi::ortalamaHesapla(int sira) {
    yoneticiDugum* yoneticiNode = this->FindPosition(sira);

    if (yoneticiNode == NULL) {

        cout<<"Hata!!";
    }


    double toplam = 0;
    if (yoneticiNode->veri->bosMU()) {

        yoneticiNode->ortalama = toplam;
        return;
    }


    int sayim = yoneticiNode->veri->boyutBul();
    for (int i = 0; i < sayim; ++i) {
        toplam += yoneticiNode->veri->dugumGetir(i);
    }
    yoneticiNode->ortalama = toplam / sayim;

}

int yoneticiListesi::rastgeleUretici(int sira) {
    int sayim = this->boyutBul();

    if (sira < 0 || sira >= boyut)
        cout<<"Gecersiz Indeks";

    srand(time(NULL));
    satirListesi* SatirListesi = this->dugumGetir(sira);

    int range = SatirListesi->boyutBul();
    if (range == 0) {
        cout<<"Boyle bir eleman yok";
    }
    int icSira = rand() % range;

    return icSira;
}

void yoneticiListesi::dugumTasi(int from, int to) {
    if (from < 0 || from >= boyut)
        cout<<"Gecersiz Indeks"<<endl;
        yoneticiDugum *silinecek;
    if (from == 0) {
        silinecek = ilk;
        ilk = ilk->sonraki;
        if (ilk != NULL) ilk->onceki = NULL;
    } else {
        yoneticiDugum *prv = FindPreviousByPosition(from);
        silinecek = prv->sonraki;
        prv->sonraki = silinecek->sonraki;
        if (silinecek->sonraki != NULL)
            silinecek->sonraki->onceki = prv;
    }
    boyut--;
    if (to < 0 || to > boyut)
        cout<<"Gecersiz Indeks";
    if (to == 0) {

        silinecek->sonraki = ilk;
        silinecek->onceki = NULL;
        ilk = silinecek;
        if (ilk->sonraki != NULL) ilk->sonraki->onceki = ilk;
    } else {
        yoneticiDugum *prv = FindPreviousByPosition(to);

        silinecek->sonraki = prv->sonraki;
        silinecek->onceki = prv;
        prv->sonraki = silinecek;
        if (prv->sonraki->sonraki != NULL)
            prv->sonraki->sonraki->onceki = prv->sonraki;
    }
    boyut++;
}

void yoneticiListesi::ortalamayaGOreSirala() {
    if (this->boyut <= 1)
        return;

    for (int step = 0; step < boyut; ++step) {


        for (int i = 0; i < boyut - step - 1; ++i) {
            yoneticiDugum *gecici = this->FindPosition(i);
            yoneticiDugum *gecici2 = gecici->sonraki;

            if (gecici->ortalama > gecici2->ortalama) {


                this->dugumTasi(i + 1, i);
            }
        }
    }

}



void yoneticiListesi::printIndex(int index, int x, int y) {
    yoneticiDugum *node = this->FindPosition(index);
    ekranYer.gotoxy(x, y);
    cout << fixed << setprecision(2);
    cout << node << "\n";
    ekranYer.gotoxy(x, y + 1);
    cout << "-----------\n";
    ekranYer.gotoxy(x, y + 2);
    cout << "|" << node->onceki << setw(3) << "|\n";
    ekranYer.gotoxy(x, y + 3);
    cout << "-----------\n";
    ekranYer.gotoxy(x, y + 4);
    cout << "|" << setw(3) <<node->ortalama<< setw(5) << "|" << endl;
    ekranYer.gotoxy(x, y + 5);
    cout << "-----------\n";
    ekranYer.gotoxy(x, y + 6);
    cout << "|" << node->sonraki << setw(3) << "|\n";
    ekranYer.gotoxy(x, y + 7);
    cout << "-----------\n\n";

}

void yoneticiListesi::temizle() {
    while (!bosMU())
        aradanSil(0);
}

yoneticiListesi::~yoneticiListesi(){
    temizle();
}