#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H

#include <iostream>

#include "UzytkownikMenager.h"

using namespace std;

class KsiazkaAdresowa
{
    UzytkownikMenager uzytkownikMenager;
public:
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami): uzytkownikMenager(nazwaPlikuZUzytkownikami){
    uzytkownikMenager.wczytajUzytkownikowZPliku();
    };
    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();
    void logowanieUzytkownika();

    void wyswietlIdZalogowanegoUzytkownika();
};
#endif
