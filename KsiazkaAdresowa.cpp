#include "KsiazkaAdresowa.h"

void KsiazkaAdresowa::rejestracjaUzytkownika()
{
    uzytkownikMenager.rejestracjaUzytkownika();
}

void KsiazkaAdresowa::wypiszWszystkichUzytkownikow()
{
    uzytkownikMenager.wypiszWszystkichUzytkownikow();
}

void KsiazkaAdresowa::logowanieUzytkownika()
{
    uzytkownikMenager.logowanieUzytkownika();
}

void KsiazkaAdresowa::wyswietlIdZalogowanegoUzytkownika()
{
    uzytkownikMenager.wyswietlIdZalogowanegoUzytkownika();
}

int KsiazkaAdresowa::pobierzIdZalogowanegoUzytkownika()
{
    uzytkownikMenager.pobierzIdZalogowanegoUzytkownika();
}

void KsiazkaAdresowa::wylogujUzytkownika()
{
    uzytkownikMenager.wylogujUzytkownika();
    cout<<endl<<"Wylogowales sie poprawnie"<<endl;
    system("pause");
}

void KsiazkaAdresowa::zmienHasloZalogowanegoUzytkownika()
{
    uzytkownikMenager.zmienHasloZalogowanegoUzytkownika();
}

void KsiazkaAdresowa::dodawanieNowegoAdresata()
{
 adresatMenager->dodawanieNowegoAdresata(pobierzIdZalogowanegoUzytkownika());
}

void KsiazkaAdresowa::wczytanieAdresatowDoPamieci(int idZalogowanegoUzytkownika)
{
 adresatMenager->wczytanieAdresatowDoPamieci(idZalogowanegoUzytkownika);
}

void KsiazkaAdresowa::wyswietlWszystkichAdresatow()
{
    adresatMenager->wyswietlWszystkichAdresatow();
}

