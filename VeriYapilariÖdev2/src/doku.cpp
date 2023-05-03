#include "doku.hpp"
using namespace std;

Doku::Doku()
{
    hucre = Hucre();
    dnaSatiri = Queue();
}
int Doku::DnaUzunlugu()
{
    return hucre.dnaUzunlugu;
}