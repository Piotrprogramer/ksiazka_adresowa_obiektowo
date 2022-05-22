#include "UzytkownikMenager.h"
#include "MetodyPomocnicze.h"
#include "PlikZUzytkownikami.h"
#include "uzytkownik.h"

void UzytkownikMenager::rejestracjaUzytkownika() {
    Uzytkownik uzytkownik = podajDaneNowegoUzytkownika();

    uzytkownicy.push_back(uzytkownik);
    plikZUzytkownikami.dopiszUzytkownikaDoPliku(uzytkownik);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

Uzytkownik UzytkownikMenager::podajDaneNowegoUzytkownika() {
    Uzytkownik uzytkownik;
    uzytkownik.ustawId(pobierzIdNowegoUzytkownika());
    string login;
    do {
        cout << endl << "Podaj login: ";
        cin >> login;
        uzytkownik.ustawLogin(login);
    } while (czyIstniejeLogin(uzytkownik.pobierzLogin()) == true);

    string haslo;
    cout << "Podaj haslo: ";
    cin >> haslo;
    uzytkownik.ustawHaslo(haslo);

    return uzytkownik;
}

int UzytkownikMenager::pobierzIdNowegoUzytkownika() {
    if (uzytkownicy.empty() == true)
        return 1;
    else
        return uzytkownicy.back().pobierzId() + 1;
}

bool UzytkownikMenager::czyIstniejeLogin(string login) {
    for(int i=0; i<uzytkownicy.size(); i++) {
        if(uzytkownicy[i].pobierzLogin() == login ) {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    }
    return false;
}

void UzytkownikMenager::wypiszWszystkichUzytkownikow() {
    for(int i=0; i<uzytkownicy.size(); i++) {
        cout<<endl<<uzytkownicy[i].pobierzId()<<endl;
        cout<<uzytkownicy[i].pobierzLogin()<<endl;
        cout<<uzytkownicy[i].pobierzHaslo()<<endl;
    }
}

void UzytkownikMenager::wczytajUzytkownikowZPliku() {
    uzytkownicy = plikZUzytkownikami.wczytajUzytkownikowZPliku();
}

void UzytkownikMenager::logowanieUzytkownika() {
    cin.sync();
    bool znalezionoLogin = false;
    string login = "", haslo = "";

    cout << endl << "Podaj login: ";
    login = metodyPomocnicze.wczytajLinie();
    vector <Uzytkownik>::iterator itr = uzytkownicy.begin();
    while (itr != uzytkownicy.end()) {
        if (itr -> pobierzLogin() == login) {
            znalezionoLogin = true;
            for (int iloscProb = 3; iloscProb > 0; iloscProb--) {
                cout << "Podaj haslo. Pozostalo prob: " << iloscProb << ": ";
                haslo = metodyPomocnicze.wczytajLinie();
                if (itr ->pobierzHaslo() == haslo) {
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                    idZalogowanegoUzytkownika = itr->pobierzId();
                    break;
                }
                if(iloscProb == 1) {
                    cout << "Wprowadzono 3 razy bledne haslo." << endl;
                    system("pause");
                    break;
                }
            }
            break;
        }
        itr++;
    }
    if(!znalezionoLogin) {
        cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
        system("pause");
    }
}

void UzytkownikMenager::zmienHasloZalogowanegoUzytkownika() {
    MetodyPomocnicze metodyPomocnicze;
    cin.sync();
    string haslo;
    bool hasloPoprawnieZmienione=false;
    cout<<endl<<"Podaj obecne haslo: ";
    haslo = metodyPomocnicze.wczytajLinie();

    vector <Uzytkownik>::iterator itr = uzytkownicy.begin();
    while (itr != uzytkownicy.end()) {
        if(itr->pobierzHaslo() == haslo && itr->pobierzId() == idZalogowanegoUzytkownika) {
            cout<<endl<<"Podaj nowe haslo: ";
            haslo = metodyPomocnicze.wczytajLinie();
            itr->ustawHaslo(haslo);
            cout<<itr->pobierzLogin()<<endl;
            cout<<"Haslo zmienione poprawnie "<<endl;
            hasloPoprawnieZmienione = true;
            zapiszWszystkichUzytkownikowDoPliku();
            system("pause");
        }
        itr++;
    }
    if(!hasloPoprawnieZmienione) {
        cout<<endl<<"Podales nieprawidlowe obecne haslo "<<endl;
        system("pause");
    }
}

void UzytkownikMenager::wylogujUzytkownika() {
    idZalogowanegoUzytkownika = 0;
}

void UzytkownikMenager::wyswietlIdZalogowanegoUzytkownika() {
    cout<<endl<<"Zalogowany uzytkownik o ID: "<<idZalogowanegoUzytkownika<<endl;
    system("pause");
}

int UzytkownikMenager::pobierzIdZalogowanegoUzytkownika() {
    return idZalogowanegoUzytkownika;
}

void UzytkownikMenager::zapiszWszystkichUzytkownikowDoPliku()
{
    plikZUzytkownikami.zapiszWszystkichUzytkownikowDoPliku(uzytkownicy);
}
