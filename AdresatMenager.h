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
    int idZalogowanegoUzytkownika;
    int idOstatniegoAdresata;
    vector <Adresat> adresaci;

    Adresat podajDaneNowegoAdresata();
    //int pobierzIdNowegoAdresata();
    //int podajIdWybranegoAdresata();
    //int pobierzIdOstatniegoAdresata();
    char wybierzOpcjeZMenuEdycja(int idEdytowanegoAdresata);
    void wyswietlDaneAdresata(Adresat adresat);

public:
    AdresatMenager(int idZalogowanegoUzytkownika, string nazwaPlikuZDresatami): plikZAdresatami(nazwaPlikuZDresatami)
    {
    adresaci = plikZAdresatami.wczytanieAdresatowDoPamieci(idZalogowanegoUzytkownika);
    idZalogowanegoUzytkownika = this->idZalogowanegoUzytkownika;

    }
    void usunAdresata();
    //void wczytanieAdresatowDoPamieci();
    void dodawanieNowegoAdresata();
    void edytujAdresata();
    void wyszukajAdresatowPoNazwisku();
    void wyszukajAdresatowPoImieniu();
    void wyswietlWszystkichAdresatow();
};

#endif
