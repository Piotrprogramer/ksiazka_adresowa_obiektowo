
#include "AdresatMenager.h"



using namespace std;

void AdresatMenager::wczytanieAdresatowDoPamieci(int idZalogowanegoUzytkownika)
{
    adresaci = plikZAdresatami.wczytanieAdresatowDoPamieci(idZalogowanegoUzytkownika);
}

void AdresatMenager::dodawanieNowegoAdresata(int idZalogowanegoUzytkownika)
{
    Adresat adresat = podajDaneNowegoAdresata(idZalogowanegoUzytkownika);

    adresat.ustawImie(metodyPomocnicze.zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresat.pobierzImie()));
    adresat.ustawNazwisko(metodyPomocnicze.zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresat.pobierzImie()));


    adresaci.push_back(adresat);
    plikZAdresatami.dopiszAdresataDoPliku(adresat);

    cout << endl << "Adresat dodany poprawnie" << endl << endl;
    system("pause");
}

Adresat AdresatMenager::podajDaneNowegoAdresata(int idZalogowanegoUzytkownika)
{
    Adresat adresat;
    adresat.ustawId(pobierzIdNowegoAdresata());
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

int AdresatMenager::pobierzIdNowegoAdresata() {
        return plikZAdresatami.pobierzIdOstatniegoAdresata()+1;
}

void AdresatMenager::wyswietlWszystkichAdresatow()
{
    for(int i=0; i<adresaci.size(); i++) {
        cout<<endl<<adresaci[i].pobierzId()<<endl;
        cout<<adresaci[i].pobierzIdUzytkownika()<<endl;
        cout<<adresaci[i].pobierzImie()<<endl;
        cout<<adresaci[i].pobierzNazwisko()<<endl;
        cout<<adresaci[i].pobierzNumerTelefonu()<<endl;
        cout<<adresaci[i].pobierzEmail()<<endl;
        cout<<adresaci[i].pobierzAdres()<<endl;
    }
}

void AdresatMenager::edytujAdresata()
{
    system("cls");
    int idEdytowanegoAdresata = 0;
    int numerLiniiEdytowanegoAdresata = 0;
    string liniaZDanymiAdresata = "";

    cout << ">>> EDYCJA WYBRANEGO ADRESATA <<<" << endl << endl;
    idEdytowanegoAdresata = podajIdWybranegoAdresata();

    char wybor;
    bool czyIstniejeAdresat = false;

    for (int i = 0; i < adresaci.size(); i++)
    {
        if (adresaci[i].pobierzId() == idEdytowanegoAdresata)
        {
            Adresat adresat;
            czyIstniejeAdresat = true;
            wybor = wybierzOpcjeZMenuEdycja(i);

            switch (wybor)
            {
            case '1':
                cout << "Podaj nowe imie: ";
                adresaci[i].ustawImie(  metodyPomocnicze.wczytajLinie() );
                plikZAdresatami.zaktualizujDaneWybranegoAdresata(adresaci[i]);
                break;
            case '2':
                cout << "Podaj nowe nazwisko: ";
                adresaci[i].ustawNazwisko( metodyPomocnicze.wczytajLinie() );
                plikZAdresatami.zaktualizujDaneWybranegoAdresata(adresaci[i]);
                break;
            case '3':
                cout << "Podaj nowy numer telefonu: ";
                adresaci[i].ustawNumerTelefonu( metodyPomocnicze.wczytajLinie() );
                plikZAdresatami.zaktualizujDaneWybranegoAdresata(adresaci[i]);
                break;
            case '4':
                cout << "Podaj nowy email: ";
                adresaci[i].ustawEmail( metodyPomocnicze.wczytajLinie() );
                plikZAdresatami.zaktualizujDaneWybranegoAdresata(adresaci[i]);
                break;
            case '5':
                cout << "Podaj nowy adres zamieszkania: ";
                adresaci[i].ustawAdres( metodyPomocnicze.wczytajLinie() );
                plikZAdresatami.zaktualizujDaneWybranegoAdresata(adresaci[i]);
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
    if (czyIstniejeAdresat == false)
    {
        cout << endl << "Nie ma takiego adresata." << endl << endl;
    }
    system("pause");
}

int AdresatMenager::podajIdWybranegoAdresata()
{
    int idWybranegoAdresata = 0;
    cout << "Podaj numer ID Adresata: ";
    idWybranegoAdresata  = metodyPomocnicze.wczytajLiczbeCalkowita();
    return idWybranegoAdresata;
}

char AdresatMenager::wybierzOpcjeZMenuEdycja(int idEdytowanegoAdresata)
{
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

void AdresatMenager::usunAdresata()
{
    int idUsuwanegoAdresata = 0;
    int numerLiniiUsuwanegoAdresata = 0;

    system("cls");
    cout << ">>> USUWANIE WYBRANEGO ADRESATA <<<" << endl << endl;
    idUsuwanegoAdresata = podajIdWybranegoAdresata();

    char znak;
    bool czyIstniejeAdresat = false;

    for (int i = 0; i < adresaci.size(); i++)
    {
        if (adresaci[i].pobierzId() == idUsuwanegoAdresata)
        {
            czyIstniejeAdresat = true;
            cout << endl << "Potwierdz naciskajac klawisz 't': ";
            znak = metodyPomocnicze.wczytajZnak();
            if (znak == 't')
            {
                plikZAdresatami.usunWybranegoAdresata(adresaci[i].pobierzId());
                adresaci.erase(adresaci.begin()+i);
                cout << endl << endl << "Szukany adresat zostal USUNIETY" << endl << endl;
                system("pause");
            }
            else
            {
                cout << endl << endl << "Wybrany adresat NIE zostal usuniety" << endl << endl;
                system("pause");
            }
        }
    }
    if (czyIstniejeAdresat == false)
    {
        cout << endl << "Nie ma takiego adresata w ksiazce adresowej" << endl << endl;
        system("pause");
    }
}

void AdresatMenager::wyszukajAdresatowPoImieniu()
{
    string imiePoszukiwanegoAdresata = "";
    int iloscAdresatow = 0;

    system("cls");
    if (!adresaci.empty())
    {
        cout << ">>> WYSZUKIWANIE ADRESATOW O IMIENIU <<<" << endl << endl;

        cout << "Wyszukaj adresatow o imieniu: ";
        imiePoszukiwanegoAdresata = metodyPomocnicze.wczytajLinie();
        imiePoszukiwanegoAdresata = metodyPomocnicze.zamienPierwszaLitereNaDuzaAPozostaleNaMale(imiePoszukiwanegoAdresata);

        for (vector <Adresat>::iterator  itr = adresaci.begin(); itr != adresaci.end(); itr++)
        {
            if (itr -> pobierzImie() == imiePoszukiwanegoAdresata)
            {
                wyswietlDaneAdresata(*itr);
                iloscAdresatow++;
            }
        }
        //wyswietlIloscWyszukanychAdresatow(iloscAdresatow);
    }
    else
    {
        cout << endl << "Ksiazka adresowa jest pusta" << endl << endl;
    }
    cout << endl;
    system("pause");
}

void AdresatMenager::wyszukajAdresatowPoNazwisku()
{
    string nazwiskoPoszukiwanegoAdresata;
    int iloscAdresatow = 0;

    system("cls");
    if (!adresaci.empty())
    {
        cout << ">>> WYSZUKIWANIE ADRESATOW O NAZWISKU <<<" << endl << endl;

        cout << "Wyszukaj adresatow o nazwisku: ";
        nazwiskoPoszukiwanegoAdresata = metodyPomocnicze.wczytajLinie();
        nazwiskoPoszukiwanegoAdresata = metodyPomocnicze.zamienPierwszaLitereNaDuzaAPozostaleNaMale(nazwiskoPoszukiwanegoAdresata);

        for (vector <Adresat>::iterator itr = adresaci.begin(); itr != adresaci.end(); itr++)
        {
            if (itr -> pobierzNazwisko() == nazwiskoPoszukiwanegoAdresata)
            {
                wyswietlDaneAdresata(*itr);
                iloscAdresatow++;
            }
        }
        //wyswietlIloscWyszukanychAdresatow(iloscAdresatow);
    }
    else
    {
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
    }
    cout << endl;
    system("pause");
}

void AdresatMenager::wyswietlDaneAdresata(Adresat adresat)
{
    cout << endl << "Id:                 " << adresat.pobierzId() << endl;
    cout << "Imie:               " << adresat.pobierzImie() << endl;
    cout << "Nazwisko:           " << adresat.pobierzNazwisko() << endl;
    cout << "Numer telefonu:     " << adresat.pobierzNumerTelefonu() << endl;
    cout << "Email:              " << adresat.pobierzEmail() << endl;
    cout << "Adres:              " << adresat.pobierzAdres() << endl;
}

