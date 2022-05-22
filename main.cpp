#include <iostream>
#include "KsiazkaAdresowa.h"

#include "PlikZAdresatami.h"
#include "AdresatMenager.h"

using namespace std;

int _main()
{
    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt");

    ksiazkaAdresowa.wczytanieAdresatowDoPamieci(2);

    ksiazkaAdresowa.wyswietlWszystkichAdresatow();
    cout<<"nowa linia"<<endl;
        ksiazkaAdresowa.wczytanieAdresatowDoPamieci(3);

    ksiazkaAdresowa.wyswietlWszystkichAdresatow();

    return 0;
}


#include "PlikZAdresatami.h"
int main()
{
    AdresatMenager adresatMenager;
    adresatMenager.wczytanieAdresatowDoPamieci(2);
    adresatMenager.wyswietlWszystkichAdresatow();

}
