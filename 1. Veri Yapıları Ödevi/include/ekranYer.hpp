/*
* File: ekranYer.hpp
* Description:Bir COORD yapısı oluşturdum ve üyelerini doldurdum.Bu, imlec ayarlayacağımız yeni konumunu belirtir.Konsol ekran arabelleği için bir tanıtıcı edindim.
(Yalnızca standart konsolu kullanıyorsunuz, yani STD_OUTPUT_HANDLE kullanabiliriz.tanıtıcıyı almak için GetStdHandle() ile birlikte.)
Son olarak, SetConsoleCursorPosition işlevini çağırdım.
* Assignment: 1.Odev
* Date: 11:18:2022
* Author: Mert Umul
*/

#ifndef ekranYer_hpp
#define ekranYer_hpp
#include <windows.h>

static class ekranYer {
public:

    static void gotoxy(int x, int y) {
        COORD c;
        c.X = x;
        c.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
    }


} ekranYer;


#endif 