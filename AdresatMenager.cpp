#include "AdresatMenager.h"

using namespace std;

void AdresatMenager::dodawanieNowegoAdresata() {
    Adresat adresat = podajDaneNowegoAdresata();

    adresat.ustawImie(metodyPomocnicze.zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresat.pobierzImie()));
    adresat.ustawNazwisko(metodyPomocnicze.zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresat.pobierzNazwisko()));

    adresaci.push_back(adresat);
    plikZAdresatami.dopiszAdresataDoPliku(adresat);

    cout << endl << "Adresat dodany poprawnie" << endl << endl;
    system("pause");
}

Adresat AdresatMenager::podajDaneNowegoAdresata() {
    Adresat adresat;

    adresat.ustawId(++idOstatniegoAdresata);
    adresat.ustawIdUzytkownika(idZalogowanegoUzytkownika);
    string imie;
    cout << "Podaj imie: ";
    cin >> imie;
    adresat.ustawImie(imie);
    string nazwisko;
    cout << "Podaj nazwisko: ";
    cin >> nazwisko;
    adresat.ustawNazwisko(nazwisko);
    string numerTelefonu;
    cout << "Podaj numer telefonu: ";
    cin >> numerTelefonu;
    adresat.ustawNumerTelefonu(numerTelefonu);
    string email;
    cout << "Podaj email: ";
    cin >> email;
    adresat.ustawEmail(email);
    string adres;
    cout << "Podaj adres: ";
    cin >> adres;
    adresat.ustawAdres(adres);

    return adresat;
}

void AdresatMenager::wyswietlWszystkichAdresatow() {
    for(int i=0; i<adresaci.size(); i++) {
        cout<<endl<<adresaci[i].pobierzId()<<endl;
        cout<<adresaci[i].pobierzIdUzytkownika()<<endl;
        cout<<adresaci[i].pobierzImie()<<endl;
        cout<<adresaci[i].pobierzNazwisko()<<endl;
        cout<<adresaci[i].pobierzNumerTelefonu()<<endl;
        cout<<adresaci[i].pobierzEmail()<<endl;
        cout<<adresaci[i].pobierzAdres()<<endl;
    }
    system("pause");
}

void AdresatMenager::edytujAdresata() {
    system("cls");
    int idEdytowanegoAdresata = 0;
    int numerLiniiEdytowanegoAdresata = 0;
    string liniaZDanymiAdresata = "";

    cout << ">>> EDYCJA WYBRANEGO ADRESATA <<<" << endl << endl;
    cout << "Podaj ID edytowanego adresata: ";
    idEdytowanegoAdresata = metodyPomocnicze.wczytajLiczbeCalkowita();

    char wybor;
    bool czyIstniejeAdresat = false;

    for (int i = 0; i < adresaci.size(); i++) {
        if (adresaci[i].pobierzId() == idEdytowanegoAdresata) {
            Adresat adresat;
            czyIstniejeAdresat = true;
            wybor = wybierzOpcjeZMenuEdycja(i);

            switch (wybor) {
            case '1':
                cout << "Podaj nowe imie: ";
                adresaci[i].ustawImie( metodyPomocnicze.zamienPierwszaLitereNaDuzaAPozostaleNaMale(metodyPomocnicze.wczytajLinie()) );
                plikZAdresatami.aktualizujDaneWybranegoAdresataWPliku(adresaci[i]);
                cout << "Nowe imie zostalo zapisane poprawnie "<<endl;
                break;

            case '2':
                cout << "Podaj nowe nazwisko: ";
                adresaci[i].ustawNazwisko( metodyPomocnicze.zamienPierwszaLitereNaDuzaAPozostaleNaMale(metodyPomocnicze.wczytajLinie()) );
                plikZAdresatami.aktualizujDaneWybranegoAdresataWPliku(adresaci[i]);
                break;
            case '3':
                cout << "Podaj nowy numer telefonu: ";
                adresaci[i].ustawNumerTelefonu( metodyPomocnicze.wczytajLinie() );
                plikZAdresatami.aktualizujDaneWybranegoAdresataWPliku(adresaci[i]);
                cout << "Nowy numer telefonu zostal zapisany poprawnie "<<endl;
                break;

            case '4':
                cout << "Podaj nowy email: ";
                adresaci[i].ustawEmail( metodyPomocnicze.wczytajLinie() );
                plikZAdresatami.aktualizujDaneWybranegoAdresataWPliku(adresaci[i]);
                cout << "Nowe email zostal zapisany poprawnie "<<endl;
                break;

            case '5':
                cout << "Podaj nowy adres zamieszkania: ";
                adresaci[i].ustawAdres( metodyPomocnicze.wczytajLinie() );
                plikZAdresatami.aktualizujDaneWybranegoAdresataWPliku(adresaci[i]);
                cout << "Now adres zostal zapisany poprawnie "<<endl;
                break;

            case '6':
                cout << endl << "Powrot do menu uzytkownika" << endl << endl;
                break;

            default:
                cout << endl << "Nie ma takiej opcji w menu! Powrot do menu uzytkownika." << endl << endl;
                break;
            }
        }
    }
    if (czyIstniejeAdresat == false) {
        cout << endl << "Nie ma takiego adresata." << endl << endl;
    }
    system("pause");
}

char AdresatMenager::wybierzOpcjeZMenuEdycja(int idEdytowanegoAdresata) {
    char wybor;

    cout << endl << "   >>> MENU  EDYCJA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "Ktore dane zaktualizowac: " << endl;
    cout << "1 - Imie: "<< adresaci[idEdytowanegoAdresata].pobierzImie()<< endl;
    cout << "2 - Nazwisko: " << adresaci[idEdytowanegoAdresata].pobierzNazwisko()<< endl;
    cout << "3 - Numer telefonu: " << adresaci[idEdytowanegoAdresata].pobierzNumerTelefonu()<< endl;
    cout << "4 - Email: " << adresaci[idEdytowanegoAdresata].pobierzEmail()<< endl;
    cout << "5 - Adres: " << adresaci[idEdytowanegoAdresata].pobierzAdres()<< endl;
    cout << "6 - Powrot " << endl;
    cout << endl << "Twoj wybor: ";
    wybor = metodyPomocnicze.wczytajZnak();

    return wybor;
}

void AdresatMenager::usunAdresata() {
    int idUsuwanegoAdresata = 0;

    system("cls");
    cout << ">>> USUWANIE WYBRANEGO ADRESATA <<<" << endl << endl;
    cout << "Podaj ID usuwanego adresata: ";
    idUsuwanegoAdresata = metodyPomocnicze.wczytajLiczbeCalkowita();

    char znak;
    bool czyIstniejeAdresat = false;

    for (int i = 0; i < adresaci.size(); i++) {
        if (adresaci[i].pobierzId() == idUsuwanegoAdresata) {
            czyIstniejeAdresat = true;
            cout << endl << "Potwierdz naciskajac klawisz 't': ";
            znak = metodyPomocnicze.wczytajZnak();
            if (znak == 't') {
                plikZAdresatami.usunWybranegoAdresata(adresaci[i].pobierzId());
                adresaci.erase(adresaci.begin()+i);

                idOstatniegoAdresata = plikZAdresatami.pobierzIdOstatniegoAdresata();

                cout << endl << endl << "Szukany adresat zostal USUNIETY" << endl << endl;
                system("pause");
            } else {
                cout << endl << endl << "Wybrany adresat NIE zostal usuniety" << endl << endl;
                system("pause");
            }
        }
    }
    if (czyIstniejeAdresat == false) {
        cout << endl << "Nie ma takiego adresata w ksiazce adresowej" << endl << endl;
        system("pause");
    }
}

void AdresatMenager::wyszukajAdresatowPoImieniu() {
    string imiePoszukiwanegoAdresata = "";
    int iloscAdresatow = 0;

    system("cls");
    if (!adresaci.empty()) {
        cout << ">>> WYSZUKIWANIE ADRESATOW O IMIENIU <<<" << endl << endl;
        cout << "Wyszukaj adresatow o imieniu: ";

        imiePoszukiwanegoAdresata = metodyPomocnicze.wczytajLinie();
        imiePoszukiwanegoAdresata = metodyPomocnicze.zamienPierwszaLitereNaDuzaAPozostaleNaMale(imiePoszukiwanegoAdresata);

        for (vector <Adresat>::iterator  itr = adresaci.begin(); itr != adresaci.end(); itr++) {
            if (itr -> pobierzImie() == imiePoszukiwanegoAdresata) {
                wyswietlDaneAdresata(*itr);
                iloscAdresatow++;
            }
        }
    } else {
        cout << endl << "Ksiazka adresowa jest pusta" << endl << endl;
    }
    cout << endl;
    system("pause");
}

void AdresatMenager::wyszukajAdresatowPoNazwisku() {
    string nazwiskoPoszukiwanegoAdresata;
    int iloscAdresatow = 0;

    system("cls");
    if (!adresaci.empty()) {
        cout << ">>> WYSZUKIWANIE ADRESATOW O NAZWISKU <<<" << endl << endl;

        cout << "Wyszukaj adresatow o nazwisku: ";
        nazwiskoPoszukiwanegoAdresata = metodyPomocnicze.wczytajLinie();
        nazwiskoPoszukiwanegoAdresata = metodyPomocnicze.zamienPierwszaLitereNaDuzaAPozostaleNaMale(nazwiskoPoszukiwanegoAdresata);

        for (vector <Adresat>::iterator itr = adresaci.begin(); itr != adresaci.end(); itr++) {
            if (itr -> pobierzNazwisko() == nazwiskoPoszukiwanegoAdresata) {
                wyswietlDaneAdresata(*itr);
                iloscAdresatow++;
            }
        }
    } else {
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
    }
    cout << endl;
    system("pause");
}

void AdresatMenager::wyswietlDaneAdresata(Adresat adresat) {
    cout << endl << "Id:                 " << adresat.pobierzId() << endl;
    cout << "Imie:               " << adresat.pobierzImie() << endl;
    cout << "Nazwisko:           " << adresat.pobierzNazwisko() << endl;
    cout << "Numer telefonu:     " << adresat.pobierzNumerTelefonu() << endl;
    cout << "Email:              " << adresat.pobierzEmail() << endl;
    cout << "Adres:              " << adresat.pobierzAdres() << endl;
}

