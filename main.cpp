#include <iostream>
#include "KsiazkaAdresowa.h"

#include "PlikZAdresatami.h"
#include "AdresatMenager.h"

using namespace std;

int main()
{
    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt");
    //ksiazkaAdresowa.wypiszWszystkichUzytkownikow();
    //ksiazkaAdresowa.rejestracjaUzytkownika();
    ksiazkaAdresowa.logowanieUzytkownika();
    //ksiazkaAdresowa.wyswietlIdZalogowanegoUzytkownika();
    //ksiazkaAdresowa.wylogujUzytkownika();
    //ksiazkaAdresowa.wyswietlIdZalogowanegoUzytkownika();
    //ksiazkaAdresowa.zmienHasloZalogowanegoUzytkownika();
    //ksiazkaAdresowa.wypiszWszystkichUzytkownikow();

    //PlikZAdresatami plikZAdresatami;
    //plikZAdresatami.wczytanieAdresatowDoPamieci();
    ksiazkaAdresowa.wczytanieAdresatowDoPamieci();

    ksiazkaAdresowa.wyswietlWszystkichAdresatow();
    ksiazkaAdresowa.dodawanieNowegoAdresata();
    ksiazkaAdresowa.wyswietlWszystkichAdresatow();


    return 0;
}
