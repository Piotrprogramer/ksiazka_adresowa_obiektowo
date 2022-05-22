#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H

#include <iostream>

#include "UzytkownikMenager.h"
#include "AdresatMenager.h"
#include "Menu.h"

using namespace std;

class KsiazkaAdresowa
{
    UzytkownikMenager uzytkownikMenager;
    AdresatMenager *adresatMenager;
    //const string NAZWA_PLIKU_Z_UZYTKOWNIKAMI;

public:
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami): uzytkownikMenager(nazwaPlikuZUzytkownikami)
    {
    adresatMenager = NULL;
    };

    ~KsiazkaAdresowa()
    {
    delete adresatMenager;
    adresatMenager = NULL;
    }

    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();
    void logowanieUzytkownika();
    void wylogujUzytkownika();
    void zmienHasloZalogowanegoUzytkownika();

    void dodawanieNowegoAdresata();
    void wczytanieAdresatowDoPamieci(int idZalogowanegoUzytkownika);
    void wyswietlWszystkichAdresatow();

    int pobierzIdZalogowanegoUzytkownika();
    void wyswietlIdZalogowanegoUzytkownika();
};
#endif
