#include <iostream>
#include "Queue.hpp"
#include "kontrol.hpp"
#include "radix.hpp"
using namespace std;

Queue::Queue()
{
    indeks = 0;
    veri = new int[128];
    ilk = -1;
    son = -1;
}
bool Queue::bosMu()
{
    if (ilk == -1)
        return true;
    else
        return false;
}

bool Queue::doluMU()
{
    if (ilk == 0 && son == 128 - 1)
    {
        return true;
    }
    return false;
}



void Queue::Ekle(int deger, int sira)
{
    if (!doluMU())
    {
         indeks = sira;
        if (ilk == -1)
            ilk = 0;
        son++;
        veri[son] = deger;
        
    }
    else
        cout << endl<< "Kuyruk Dolu!!!!!";
}
int Queue::Cikar()
{
    int deger;
    if (!bosMu())
    {
        deger = veri[ilk];
        if (ilk >= son)
        { 
            ilk = -1;
            son = -1;
        }
        else
        {
            ilk++;
        }
        cout << endl
             << "Silinen veri -> " << deger ;
        return (deger);
        
    }
    else
    {
        cout << "Kuyruk Bos!!!!!" << endl;
        return (-1);
        
    }
}
void Queue::degerAzalt()
{
    for (int i = ilk; i <= son; i++)
    {
        if (veri[i] % 2 == 0)
            veri[i] *= 0.5;
    }
}
int Queue::ortaDeger()
{
    return veri[(son - ilk + 1) / 2];
}


void Queue::yazdir()
{
    int i;
    if (!bosMu())
    {
        cout << son - ilk + 1 << "\t"<< " satir " << indeks << "\t";
        for (i = ilk; i <= son; i++)
        {
            cout << veri[i] << " ";
        }
        cout << endl;
        
    }
    else
        cout << endl<< "Kuyruk Bos!!!!!" << endl;
}



void Queue::radixSortSirala()
{
    Radix radix;
    radix.radixSirala(veri, son - ilk + 1);
}