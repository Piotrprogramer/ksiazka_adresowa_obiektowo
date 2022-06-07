#ifndef UZYTKOWNIKMENAGER_H
#define UZYTKOWNIKMENAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "Uzytkownik.h"
#include "PlikZUzytkownikami.h"


using namespace std;

class UzytkownikMenager
{
    int idZalogowanegoUzytkownika;
    vector <Uzytkownik> uzytkownicy;
    PlikZUzytkownikami plikZUzytkownikami;

    Uzytkownik podajDaneNowegoUzytkownika();
    int pobierzIdNowegoUzytkownika();
    bool czyIstniejeLogin(string login);
    //string zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik);
    MetodyPomocnicze metodyPomocnicze;

public:
    UzytkownikMenager(string nazwaPlikuZUzytkownikami): plikZUzytkownikami(nazwaPlikuZUzytkownikami)
    {
    wczytajUzytkownikowZPliku();
    };
    void rejestracjaUzytkownika();
    //void wypiszWszystkichUzytkownikow();
    void wczytajUzytkownikowZPliku();

    int logowanieUzytkownika();
    void wylogujUzytkownika();
    void zmienHasloZalogowanegoUzytkownika();
    //void zapiszWszystkichUzytkownikowDoPliku();

    int pobierzIdZalogowanegoUzytkownika();
    //void wyswietlIdZalogowanegoUzytkownika();
};

#endif
