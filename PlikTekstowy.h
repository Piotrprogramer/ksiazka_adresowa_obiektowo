#ifndef PLIK_TEKSTOWY_H
#define PLIK_TEKSTOWY_H

#include <fstream>
#include <iostream>

using namespace std;


class PlikTekstowy
{
    public:
    void usunPlik(string nazwaPlikuZAdresatami);
    void zmienNazwePliku(string nazwaTymczasowegoPlikuZRozszerzeniem, string nazwaPlikuZRozszerzeniem);
};

#endif
