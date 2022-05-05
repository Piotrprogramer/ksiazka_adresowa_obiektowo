#include <iostream>
#include "KsiazkaAdresowa.h"

using namespace std;

int main()
{
    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt");
    ksiazkaAdresowa.wypiszWszystkichUzytkownikow();
    ksiazkaAdresowa.wyswietlIdZalogowanegoUzytkownika();
    //ksiazkaAdresowa.rejestracjaUzytkownika();
    ksiazkaAdresowa.logowanieUzytkownika();
    ksiazkaAdresowa.wyswietlIdZalogowanegoUzytkownika();
    //ksiazkaAdresowa.wypiszWszystkichUzytkownikow();
    return 0;
}
