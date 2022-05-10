#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H

#include <iostream>

#include "UzytkownikMenager.h"
#include "AdresatMenager.h"

using namespace std;

class KsiazkaAdresowa
{
    UzytkownikMenager uzytkownikMenager;
    AdresatMenager adresatMenager;

public:

    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami): uzytkownikMenager(nazwaPlikuZUzytkownikami){
    uzytkownikMenager.wczytajUzytkownikowZPliku();
    };
    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();
    void logowanieUzytkownika();
    void wylogujUzytkownika();
    void zmienHasloZalogowanegoUzytkownika();

    void dodawanieNowegoAdresata();
    void wczytanieAdresatowDoPamieci();
    void wyswietlWszystkichAdresatow();

    int pobierzIdZalogowanegoUzytkownika();
    void wyswietlIdZalogowanegoUzytkownika();
};
#endif
