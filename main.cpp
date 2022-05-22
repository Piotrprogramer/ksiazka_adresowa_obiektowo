#include <iostream>
#include "KsiazkaAdresowa.h"

#include "PlikZAdresatami.h"
#include "AdresatMenager.h"

using namespace std;

int main()
{

    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt");
    ksiazkaAdresowa.menu.wybierzOpcjeZMenuGlownego();
    ksiazkaAdresowa.menu.wybierzOpcjeZMenuUzytkownika();

    ksiazkaAdresowa.logowanieUzytkownika();
    ksiazkaAdresowa.wyswietlWszystkichAdresatow();
    ksiazkaAdresowa.wylogujUzytkownika();
    ksiazkaAdresowa.rejestracjaUzytkownika();
    ksiazkaAdresowa.logowanieUzytkownika();
    ksiazkaAdresowa.dodawanieNowegoAdresata();
    ksiazkaAdresowa.wyswietlWszystkichAdresatow();
    ksiazkaAdresowa.wylogujUzytkownika();


    //ksiazkaAdresowa.wyswietlWszystkichAdresatow();
    //ksiazkaAdresowa.wyswietlWszystkichAdresatow();

    return 0;
}

#include "Menu.h"
int Menu_main()
{
    Menu menu;
    menu.wybierzOpcjeZMenuGlownego();
    menu.wybierzOpcjeZMenuUzytkownika();
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
