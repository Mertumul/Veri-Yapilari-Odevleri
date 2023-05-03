#include <iostream>
#include "radix.hpp"
#include "kontrol.hpp"
using namespace std;

int Radix::maksimumBul(int dizi[], int n)
{
    int maxValue = dizi[0];
    for (int i = 1; i < n; i++)
        if (dizi[i] > maxValue)
            maxValue = dizi[i];
    return maxValue;
}

void Radix::sayiSirala(int dizi[], int n, int exp)
{
    int cikti[128]; 
    int i, say[10] = {0};

    for (i = 0; i < n; i++)
        say[(dizi[i] / exp) % 10]++;

    for (i = 1; i < 10; i++)
        say[i] += say[i - 1];

    for (i = n - 1; i >= 0; i--)
    {
        cikti[say[(dizi[i] / exp) % 10] - 1] = dizi[i];
        say[(dizi[i] / exp) % 10]--;
    }

    for (i = 0; i < n; i++)
        dizi[i] = cikti[i];
}

void Radix::radixSirala(int dizi[], int n)
{
    int m = maksimumBul(dizi, n);
    for (int exp = 1; m / exp > 0; exp *= 10)
        sayiSirala  (dizi, n, exp);
}

void Radix::yazdir(int dizi[], int n)
{
    for (int i = 0; i < n; i++)
        cout << dizi[i] << " ";
    cout << endl;
}
