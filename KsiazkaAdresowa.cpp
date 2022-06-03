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
    adresatMenager = new AdresatMenager(uzytkownikMenager.pobierzIdZalogowanegoUzytkownika(), nazwaPlikuZAdresatami);
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

    delete adresatMenager;
    adresatMenager = NULL;

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

char KsiazkaAdresowa::wybierzOpcjeZMenuGlownego()
{
    while(1){
    switch (menu.wybierzOpcjeZMenuGlownego()){
    case '1': {
        uzytkownikMenager.rejestracjaUzytkownika();
        break;
        }
    case '2': {
        logowanieUzytkownika();
        if(uzytkownikMenager.pobierzIdZalogowanegoUzytkownika() > 0 ) wybierzOpcjeZMenuUzytkownika();
        break;
        }
    case '9': {
        return 0;
        }
    }
    }
}

void KsiazkaAdresowa::wybierzOpcjeZMenuUzytkownika()
{
    while( uzytkownikMenager.pobierzIdZalogowanegoUzytkownika() > 0){
        switch(menu.wybierzOpcjeZMenuUzytkownika()){
            case '1':{
                dodawanieNowegoAdresata();
                 break;
                }
            case '2':{
                adresatMenager->wyszukajAdresatowPoImieniu();
                break;
                }
            case '3':{

                adresatMenager->wyszukajAdresatowPoNazwisku();
                break;
                }
            case '4':{
                adresatMenager->wyswietlWszystkichAdresatow();
                break;
                }
            case '5':{
                adresatMenager->usunAdresata();
                break;
                }
            case '6':{
                adresatMenager->edytujAdresata();
                break;
                }
            case '7':{
                uzytkownikMenager.zmienHasloZalogowanegoUzytkownika();
                break;
                }
            case '8':{
                uzytkownikMenager.wylogujUzytkownika();
                break;
                }
            }
    }
}

