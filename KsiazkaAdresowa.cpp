#include "KsiazkaAdresowa.h"

void KsiazkaAdresowa::rejestracjaUzytkownika() {
    uzytkownikMenager.rejestracjaUzytkownika();
}

void KsiazkaAdresowa::logowanieUzytkownika() {
    int idUzytkownika = 0;
    idUzytkownika = uzytkownikMenager.logowanieUzytkownika();
    if (idUzytkownika > 0) adresatMenager = new AdresatMenager(idUzytkownika, nazwaPlikuZAdresatami);
}

void KsiazkaAdresowa::wylogujUzytkownika() {
    uzytkownikMenager.wylogujUzytkownika();

    delete adresatMenager;
    adresatMenager = NULL;

    cout<<endl<<"Wylogowales sie poprawnie"<<endl;
    system("pause");
}

void KsiazkaAdresowa::zmienHasloZalogowanegoUzytkownika() {
    uzytkownikMenager.zmienHasloZalogowanegoUzytkownika();
}

void KsiazkaAdresowa::wyswietlWszystkichAdresatow() {
    adresatMenager->wyswietlWszystkichAdresatow();
}

char KsiazkaAdresowa::wybierzOpcjeZMenuGlownego() {
    while(1) {
        switch (menu.wybierzOpcjeZMenuGlownego()) {
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

void KsiazkaAdresowa::wybierzOpcjeZMenuUzytkownika() {
    while( uzytkownikMenager.pobierzIdZalogowanegoUzytkownika() > 0) {
        switch(menu.wybierzOpcjeZMenuUzytkownika()) {
        case '1': {
            adresatMenager->dodawanieNowegoAdresata();
            break;
        }
        case '2': {
            adresatMenager->wyszukajAdresatowPoImieniu();
            break;
        }
        case '3': {

            adresatMenager->wyszukajAdresatowPoNazwisku();
            break;
        }
        case '4': {
            adresatMenager->wyswietlWszystkichAdresatow();
            break;
        }
        case '5': {
            adresatMenager->usunAdresata();
            break;
        }
        case '6': {
            adresatMenager->edytujAdresata();
            break;
        }
        case '7': {
            uzytkownikMenager.zmienHasloZalogowanegoUzytkownika();
            break;
        }
        case '8': {
            uzytkownikMenager.wylogujUzytkownika();
            break;
        }
        }
    }
}
