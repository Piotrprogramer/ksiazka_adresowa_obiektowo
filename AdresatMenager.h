#ifndef ADRESAT_MENAGER_H
#define ADRESAT_MENAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>
#include "Adresat.h"
#include "PlikZAdresatami.h"
#include "MetodyPomocnicze.h"

using namespace std;

class AdresatMenager {
    PlikZAdresatami plikZAdresatami;
    MetodyPomocnicze metodyPomocnicze;
    vector <Adresat> adresaci;
    //string nazwaPlikuZDresatami;

    Adresat podajDaneNowegoAdresata(int idZalogowanegoUzytkownika);
    int pobierzIdNowegoAdresata();
    int podajIdWybranegoAdresata();
    char wybierzOpcjeZMenuEdycja(int idEdytowanegoAdresata);

public:
    AdresatMenager(int idZalogowanegoUzytkownika, string nazwaPlikuZDresatami): plikZAdresatami(nazwaPlikuZDresatami)
    {
    wczytanieAdresatowDoPamieci(idZalogowanegoUzytkownika);
    //this->nazwaPlikuZDresatami = nazwaPlikuZDresatami;
    }

    void wczytanieAdresatowDoPamieci(int idZalogowanegoUzytkownika);
    void dodawanieNowegoAdresata(int idZalogowanegoUzytkownika);
    void edytujAdresata();
    void wyswietlWszystkichAdresatow();
};

#endif
