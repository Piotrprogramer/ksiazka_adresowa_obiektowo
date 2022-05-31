
#include "AdresatMenager.h"

using namespace std;

void AdresatMenager::wczytanieAdresatowDoPamieci(int idZalogowanegoUzytkownika)
{
    adresaci = plikZAdresatami.wczytanieAdresatowDoPamieci(idZalogowanegoUzytkownika);
}

void AdresatMenager::dodawanieNowegoAdresata(int idZalogowanegoUzytkownika)
{
    Adresat adresat = podajDaneNowegoAdresata(idZalogowanegoUzytkownika);

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
                adresaci[i].ustawNazwisko( metodyPomocnicze.zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresaci[i].pobierzNazwisko()) );
                //zaktualizujDaneWybranegoAdresata(adresaci[i], idEdytowanegoAdresata);
                break;
            case '3':
                cout << "Podaj nowy numer telefonu: ";
                adresaci[i].ustawNumerTelefonu( metodyPomocnicze.wczytajLinie() );
                //zaktualizujDaneWybranegoAdresata(adresaci[i], idEdytowanegoAdresata);
                break;
            case '4':
                cout << "Podaj nowy email: ";
                adresaci[i].ustawEmail( metodyPomocnicze.wczytajLinie() );
                //zaktualizujDaneWybranegoAdresata(adresaci[i], idEdytowanegoAdresata);
                break;
            case '5':
                cout << "Podaj nowy adres zamieszkania: ";
                adresaci[i].ustawAdres( metodyPomocnicze.wczytajLinie() );
                //zaktualizujDaneWybranegoAdresata(adresaci[i], idEdytowanegoAdresata);
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
    cout << "1 - Imie- "<< adresaci[idEdytowanegoAdresata].pobierzImie()<< endl;
    cout << "2 - Nazwisko- " << adresaci[idEdytowanegoAdresata].pobierzNazwisko()<< endl;
    cout << "3 - Numer telefonu- " << adresaci[idEdytowanegoAdresata].pobierzNumerTelefonu()<< endl;
    cout << "4 - Email- " << adresaci[idEdytowanegoAdresata].pobierzEmail()<< endl;
    cout << "5 - Adres- " << adresaci[idEdytowanegoAdresata].pobierzAdres()<< endl;
    cout << "6 - Powrot " << endl;
    cout << endl << "Twoj wybor: ";
    wybor = metodyPomocnicze.wczytajZnak();

    return wybor;
}

