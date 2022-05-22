#include <iostream>
#include "KsiazkaAdresowa.h"

#include "PlikZAdresatami.h"
#include "AdresatMenager.h"

using namespace std;

int main()
{
    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt");


    ksiazkaAdresowa.wypiszWszystkichUzytkownikow();
    ksiazkaAdresowa.logowanieUzytkownika();
    ksiazkaAdresowa.wyswietlWszystkichAdresatow();
    ksiazkaAdresowa.wylogujUzytkownika();
    ksiazkaAdresowa.wyswietlWszystkichAdresatow();
    //ksiazkaAdresowa.wyswietlWszystkichAdresatow();

    return 0;
}

#include "UzytkownikMenager.h"
int UzytkownikMenager_main()
{
    UzytkownikMenager uzytkownikMenager("Uzytkownicy.txt");
    //uzytkownikMenager.wczytajUzytkownikowZPliku();
    uzytkownikMenager.wypiszWszystkichUzytkownikow();

}

#include "PlikZAdresatami.h"
int PlikZAdresatami_main()
{
    AdresatMenager adresatMenager(1);
    //adresatMenager.wczytanieAdresatowDoPamieci(2);
    adresatMenager.wyswietlWszystkichAdresatow();
    adresatMenager.dodawanieNowegoAdresata(1);
    adresatMenager.wyswietlWszystkichAdresatow();
}
