#include <iostream>
#include "KsiazkaAdresowa.h"

#include "PlikZAdresatami.h"
#include "AdresatMenager.h"

using namespace std;

int _main()
{

    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt", "Adresaci.txt");

    ksiazkaAdresowa.wypiszWszystkichUzytkownikow();

    ksiazkaAdresowa.logowanieUzytkownika();

    ksiazkaAdresowa.dodawanieNowegoAdresata();

    ksiazkaAdresowa.wyswietlWszystkichAdresatow();

    ksiazkaAdresowa.wylogujUzytkownika();

    return 0;

}

#include "AdresatMenager.h"
int main(){

AdresatMenager adresatMenager(2,"Adresaci.txt");
adresatMenager.wczytanieAdresatowDoPamieci(2);
adresatMenager.wyswietlWszystkichAdresatow();
adresatMenager.edytujAdresata();
adresatMenager.wyswietlWszystkichAdresatow();




}
