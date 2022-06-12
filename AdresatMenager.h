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
    int const ID_ZALOGOWANEGO_UZYTKOWNIKA;
    int idOstatniegoAdresata ;
    vector <Adresat> adresaci;

    Adresat podajDaneNowegoAdresata();
    char wybierzOpcjeZMenuEdycja(int idEdytowanegoAdresata);
    void wyswietlDaneAdresata(Adresat adresat);

public:
    AdresatMenager(int idZalogowanegoUzytkownika, string nazwaPlikuZAdresatami)
        :ID_ZALOGOWANEGO_UZYTKOWNIKA(idZalogowanegoUzytkownika), plikZAdresatami(nazwaPlikuZAdresatami) {
        adresaci = plikZAdresatami.wczytanieAdresatowDoPamieci(idZalogowanegoUzytkownika);
        idOstatniegoAdresata = plikZAdresatami.pobierzIdOstatniegoAdresata();
    }

    void usunAdresata();
    void dodawanieNowegoAdresata();
    void edytujAdresata();
    void wyszukajAdresatowPoNazwisku();
    void wyszukajAdresatowPoImieniu();
    void wyswietlWszystkichAdresatow();
};

#endif
