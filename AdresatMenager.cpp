
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

