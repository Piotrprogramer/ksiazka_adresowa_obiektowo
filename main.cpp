#include <iostream>
#include "KsiazkaAdresowa.h"

#include "PlikZAdresatami.h"
#include "AdresatMenager.h"

using namespace std;

int main()
{

    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt", "Adresaci.txt");

    ksiazkaAdresowa.wypiszWszystkichUzytkownikow();

    ksiazkaAdresowa.logowanieUzytkownika();

    ksiazkaAdresowa.dodawanieNowegoAdresata();
    ksiazkaAdresowa.dodawanieNowegoAdresata();
    ksiazkaAdresowa.dodawanieNowegoAdresata();
    ksiazkaAdresowa.dodawanieNowegoAdresata();
    ksiazkaAdresowa.dodawanieNowegoAdresata();

    ksiazkaAdresowa.wyswietlWszystkichAdresatow();

    ksiazkaAdresowa.wylogujUzytkownika();

    return 0;

}
