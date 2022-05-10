#include <iostream>
#include "KsiazkaAdresowa.h"

#include "PlikZAdresatami.h"
#include "AdresatMenager.h"

using namespace std;

int main()
{
    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt");
    //ksiazkaAdresowa.logowanieUzytkownika();
    ksiazkaAdresowa.wczytanieAdresatowDoPamieci();

    ksiazkaAdresowa.wyswietlWszystkichAdresatow();
    ksiazkaAdresowa.dodawanieNowegoAdresata();
    ksiazkaAdresowa.wyswietlWszystkichAdresatow();


    return 0;
}
