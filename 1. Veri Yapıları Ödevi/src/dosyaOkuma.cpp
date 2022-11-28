/*
* File: dosyaOkuma.cpp
* Description:Burada verilen dosyayı okutturmaya dair fonksiyonlar yazdim.Bir adet kurucu fonkisyon bulunuyor bu fonksiyon dosya adini alıyor paramete olarak ve verilen 
dosyanin satir sayisini  satirSayisi() fonksiyonu yardimiyla hesapliyor ve döngü yardımıyla kac tane satir varsa o kadar yeni satir listesi olusturuyor.SatirSayisi fonksiyonu
dosyanin icinde gezerek  satir sayisini hesapliyor, satirOku() fonksiyonu bu dosyanın verilerini satira kaydediyor yani dosyayı okuyor. yoneticiListesiDoldur() ise okunan 
dosyayi bagli listeye ekliyor.En sonunda bir adet yıkıcı fonksiyonumuz var ,bu fonksiyon kullanılan listeyi siliyor boşa yer kaplamasın diye.
* @Course:1.Ogretim Bgrubeu
* Assignment: 1.Odev
* Date: 10:18:2022
* Author: Mert Umul
*/

#include "dosyaOkuma.hpp"
dosyaOkuma::dosyaOkuma(string dosyaAdi){
    this->dosyaAdi = dosyaAdi;

    int numlines = satirSayisi();
    this->satir = new satirListesi*[numlines];
    for (int i = 0; i < numlines; i++) {
        this->satir[i] = new satirListesi();
    }
}
int dosyaOkuma::satirSayisi(){
    int satirSayisi = 0;
    ifstream in(this->dosyaAdi);
    string unused;
    while (getline(in, unused) )
        ++satirSayisi;
    in.close();
    return satirSayisi;
}

void dosyaOkuma::satirOku(){
    int sira;
    string line;
    string str;
    ifstream myfile (this->dosyaAdi);
    if (myfile.is_open())
    {
       while (getline(myfile, line)) {
            istringstream ss(line);

        while (getline(ss, str, ' ')) {
            this->satir[sira]->ekle(stoi(str));

        }
        sira++;

    }
        myfile.close();
    }
    else cout << "Dosya acilamadi"; 

}

yoneticiListesi *dosyaOkuma::yoneticiListesiDoldur()
{

    satirOku();
    yoneticiListesi *gecici=new yoneticiListesi();
    int sayim=satirSayisi();
    for(int i=0;i<sayim;++i){
        gecici->ekle(this->satir[i]);
    }
    return gecici;
}

dosyaOkuma::~dosyaOkuma(){

    int sayim=satirSayisi();    
    for (int i = 0; i < sayim && (satir!=0); i++){
			if(satir[i]!=0) 
                delete satir[i];
		}
		delete[] satir;

}