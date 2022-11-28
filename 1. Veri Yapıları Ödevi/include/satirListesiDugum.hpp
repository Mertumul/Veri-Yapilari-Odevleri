


#ifndef satirListesiDugum_hpp
#define satirListesiDugum_hpp
#include <iostream>
using namespace std;

class satirListesiDugum
{
public:
    int veri;
    satirListesiDugum *sonraki;
    satirListesiDugum *onceki;
    satirListesiDugum(const int veri);
    satirListesiDugum(const int veri, satirListesiDugum *sonraki);
    satirListesiDugum(const int veri, satirListesiDugum *sonraki, satirListesiDugum *onceki);
};

#endif