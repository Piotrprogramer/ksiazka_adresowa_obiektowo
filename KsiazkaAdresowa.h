#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H

#include <iostream>

#include "UzytkownikMenager.h"
#include "AdresatMenager.h"
#include "Menu.h"

using namespace std;

class KsiazkaAdresowa {
    Menu menu;
    UzytkownikMenager uzytkownikMenager;
    AdresatMenager *adresatMenager;
    string nazwaPlikuZAdresatami;

public:
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami, string nazwaPlikuZAdresatami): uzytkownikMenager(nazwaPlikuZUzytkownikami) {
        this -> nazwaPlikuZAdresatami = nazwaPlikuZAdresatami;
        adresatMenager = NULL;
    };

    ~KsiazkaAdresowa() {
        delete adresatMenager;
        adresatMenager = NULL;
    };

    void rejestracjaUzytkownika();
    void logowanieUzytkownika();
    void wylogujUzytkownika();
    void zmienHasloZalogowanegoUzytkownika();
    void wyswietlWszystkichAdresatow();
    void wybierzOpcjeZMenuUzytkownika();
    char wybierzOpcjeZMenuGlownego();
};
#endif
