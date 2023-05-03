
#include <iostream>
#include <climits>
#include "ikiliAramaAgaci.hpp"

using namespace std;

Dugum::Dugum()
{
    dnaSatiri = Queue();
    sol = NULL;
    sag = NULL;
}

IAA::IAA()
{
    index = 0;
    veriCek = new Queue[20];
    dugum = new Dugum;
   
    
}

int IAA::yukseklikGetir(Dugum *kok)
{
    if (kok == NULL)
        return -1;
    return (kok->yukseklik);
}

int IAA::denge(Dugum *kok)
{
    if (kok == nullptr)
        return 0;

    int sag = denge(kok->sag);
    int sol = denge(kok->sol);
    kok->yukseklik = abs(sol - sag);
    return (1 + max(sag, sol));
}

int IAA::dengeDegerGetir(Dugum *kok)
{
    if (kok == NULL)
        return 0;
    return (yukseklikGetir(kok->sol) - yukseklikGetir(kok->sag));
}

void IAA::postOrder(Dugum *kok)
{
    if (kok == NULL)
        return;
    postOrder(kok->sol);
    postOrder(kok->sag);
    cout<<kok->veri;
}

void IAA::mutasyon(Dugum *kok)
{
    if (kok == NULL)
        return;
    mutasyon(kok->sol);
    mutasyon(kok->sag);
    veriCek[index++] = kok->dnaSatiri;
}

Dugum *IAA::ekle(Dugum *kok, int new_data, Queue mData)
{
    if (kok == NULL)
    {
        kok = new Dugum;
        kok->veri = new_data;
        kok->dnaSatiri = mData;
        kok->sol = NULL;
        kok->sag = NULL;
        kok->yukseklik = 0;
        return kok;
    }
    if (kok->veri < new_data)
        kok->sag = ekle(kok->sag, new_data, mData);
    else
        kok->sol = ekle
        
    (kok->sol, new_data, mData);

    kok->yukseklik = max(yukseklikGetir(kok->sol), yukseklikGetir(kok->sag)) + 1;
}

IAA::~IAA()
{
    delete[] dugum;
}
