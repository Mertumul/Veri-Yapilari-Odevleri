#ifndef doku_hpp
#define doku_hpp
#include <iostream>
#include "hucre.hpp"
#include "queue.hpp"


class Doku
{
public:
    Doku();
    Hucre hucre;
    Queue dnaSatiri;
    int DnaUzunlugu();
};

#endif