#include <iostream>
#include "KsiazkaAdresowa.h"

#include "PlikZAdresatami.h"
#include "AdresatMenager.h"

using namespace std;

int main()
{

    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt", "Adresaci.txt");

    ksiazkaAdresowa.wybierzOpcjeZMenuGlownego();
    /*
    ksiazkaAdresowa.wybierzOpcjeZMenuUzytkownika();

    ksiazkaAdresowa.wypiszWszystkichUzytkownikow();

    ksiazkaAdresowa.logowanieUzytkownika();

    ksiazkaAdresowa.dodawanieNowegoAdresata();

    ksiazkaAdresowa.wyswietlWszystkichAdresatow();

    ksiazkaAdresowa.wylogujUzytkownika();
    */

    return 0;

}

#include "AdresatMenager.h"
int AdresatMenager_main(){

AdresatMenager adresatMenager(2,"Adresaci.txt");
adresatMenager.wczytanieAdresatowDoPamieci(2);
adresatMenager.wyswietlWszystkichAdresatow();
//adresatMenager.edytujAdresata();
//adresatMenager.dodawanieNowegoAdresata(2);
//adresatMenager.dodawanieNowegoAdresata(2);
system("pause");
//adresatMenager.wyswietlWszystkichAdresatow();
//adresatMenager.usunAdresata();
adresatMenager.wyszukajAdresatowPoImieniu();
}

#include "Menu.h"

int Menu_main(){

Menu menu;
menu.wybierzOpcjeZMenuUzytkownika();
}
