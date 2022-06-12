#ifndef METODYPOMOCNICZE_H
#define METODYPOMOCNICZE_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

class MetodyPomocnicze{

    public:
    static string konwerjsaIntNaString(int liczba);
    string wczytajLinie();
    static int konwersjaStringNaInt(string liczba);
    char wczytajZnak();
    int wczytajLiczbeCalkowita();
    string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);
};
#endif
