#include "radix.hpp"
#include "ikiliAramaAgaci.hpp"
#include "kontrol.hpp"
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

Kontrol::Kontrol()
{
    int ks = kacSatir();
    dosyaSat = 0;
    organSayisi = ks / 20;
    sistemSayisi = organSayisi / 100;
    organ = new Organ[organSayisi + 1];
    sistem = new Sistem[sistemSayisi * 100 + 1];
    veri_Oku();
}

int Kontrol::kacSatir()
{
    int satirSayisi = 0;
    ifstream in(dosyAdi);
    string unused;
    while (getline(in, unused) )
        ++satirSayisi;
    in.close();
    return satirSayisi;

}

void Kontrol::veri_Oku()
{
    Radix radix;
    Doku doku;
    IAA iaa;
    Dugum *kok = new Dugum();
    kok = NULL;
    sistem = new Sistem[sistemSayisi + 1];
    string str;
    ifstream dosya;
    dosya.open(dosyAdi);
    int bf;
    int mf = -7;
    int o = 0;
    int bar = 0;
    int uzunluk;
    
    string hucreDegeri;
    while (getline(dosya, str))
    {
        doku = Doku();
        str.erase(str.find_last_not_of(" ") + 1);
        string arr[128];
        uzunluk = 0;
        stringstream ssin(str);

        while (ssin.good() && uzunluk < 1024)
        {
            ssin >> hucreDegeri;
            doku.dnaSatiri.Ekle(stoi(hucreDegeri), bar);
            ++uzunluk;
        }
        organ[o].doku[bar % 20] = doku;
        if (bar % 20 == 0)
        {
            iaa.~IAA();
            kok = new Dugum();
            kok = NULL;
            for (int i = 0; i < 20; i++)
            {
                organ[o].doku[i].dnaSatiri.radixSortSirala();
                kok = iaa.ekle(kok, organ[o].doku[i].dnaSatiri.ortaDeger(), organ[o].doku[i].dnaSatiri);
            }
            bf = iaa.dengeDegerGetir(kok);
            sistem->organ[o] = bf % mf;
            sistem->mutasyonluOrgan[o] = bf % mf;
            if (kok->veri % 50 == 0)
            {
                iaa.index = 0;
                iaa.veriCek = new Queue[20];
                iaa.mutasyon(kok);
                for (int i = 0; i < 20; i++)
                {
                    iaa.veriCek[i].degerAzalt();
                    iaa.veriCek[i].radixSortSirala();
                }
                IAA temp;
                kok = NULL;
                for (int i = 0; i < 20; i++)
                {
                    kok = iaa.ekle(kok, iaa.veriCek[i].ortaDeger(), Queue());
                }
                bf = temp.dengeDegerGetir(kok);
                sistem->mutasyonluOrgan[o] = bf % mf;
                kok = NULL;
            }
            o++;
        }
        bar++;
    }
    dosya.close();
    system("cls");
    cout << "---------------------ORGANIZMA---------------------" << endl;
    for (int i = 1; i < organSayisi + 1; i++)
    {
        if (!(sistem->organ[i] >= -1 && sistem->organ[i] <= 1))
            cout << "#";
        else
            cout << " ";
        if (i % 100 == 0)
            cout << endl;
    }
    cin.ignore();
    system("cls");
    cout << "---------------------ORGANIZMA (MUTASYONA UGRADI)---------------------" << endl;
    ;
    for (int i = 1; i < organSayisi + 1; i++)
    {
        if (!(sistem->mutasyonluOrgan[i] >= -1 && sistem->mutasyonluOrgan[i] <= 1))
            cout << "#";
        else
            cout << " ";
        if (i % 100 == 0)
            cout << endl;
    }
}

void Kontrol::veriOku(int organIndeks)
{
    Radix radix;
    Doku doku;
    string str;
    ifstream dosya;
    dosya.open(dosyAdi);
    int bar = 0;
    int uzunluk;
    string hucreDegeri;
    while (getline(dosya, str))
    {
        if (bar >= organIndeks * 20 && bar < 20 + organIndeks * 20)
        {
            doku = Doku();
            str.erase(str.find_last_not_of(" ") + 1);
            string arr[128];
            uzunluk = 0;
            stringstream ssin(str);

            while (ssin.good() && uzunluk < 1024)
            {
                ssin >> hucreDegeri;
                doku.dnaSatiri.Ekle(stoi(hucreDegeri), bar);
                ++uzunluk;
            }
            organ[organIndeks].doku[bar % 20] = doku;
        }

        bar++;
    }
    dosya.close();
}
