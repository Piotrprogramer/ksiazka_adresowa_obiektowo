#ifndef METODYPOMOCNICZE_H
#define METODYPOMOCNICZE_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>
#include <algorithm>

//#include "Uzytkownik.h"

using namespace std;

class MetodyPomocnicze
{
    public:
    static string konwerjsaIntNaString(int liczba);
    string wczytajLinie();
    int konwersjaStringNaInt(string liczba);
    char wczytajZnak();
    int wczytajLiczbeCalkowita();
    string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);
};

#endif
