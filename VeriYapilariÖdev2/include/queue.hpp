#ifndef queue_hpp
#define queue_hpp

class Queue
{
private:
    int *veri, ilk, son, indeks;

public:
    Queue();
    bool doluMU();
    bool bosMu();
    void Ekle(int value, int sira);
    int Cikar();
    void yazdir();
    int ortaDeger();
    void radixSortSirala();
    void degerAzalt();
};

#endif