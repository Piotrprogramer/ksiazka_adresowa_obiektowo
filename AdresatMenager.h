#ifndef ADRESAT_MENAGER_H
#define ADRESAT_MENAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>
#include "Adresat.h"
#include "PlikZAdresatami.h"

using namespace std;

class AdresatMenager {
    vector <Adresat> adresaci;
    PlikZAdresatami plikZAdresatami;
    Adresat podajDaneNowegoAdresata(int idZalogowanegoUzytkownika);
    int pobierzIdNowegoAdresata();

public:
    AdresatMenager(int idZalogowanegoUzytkownika, string nazwaPlikuZDresatami): plikZAdresatami(nazwaPlikuZDresatami)
    {
    wczytanieAdresatowDoPamieci(idZalogowanegoUzytkownika);
    }

    void wczytanieAdresatowDoPamieci(int idZalogowanegoUzytkownika);
    void dodawanieNowegoAdresata(int idZalogowanegoUzytkownika);
    void wyswietlWszystkichAdresatow();
};

#endif
