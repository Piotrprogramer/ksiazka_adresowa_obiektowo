
#include "PlikZAdresatami.h"


void PlikZAdresatami::dopiszAdresataDoPliku(Adresat adresat)
{
    string liniaZDanymiAdresata = "";
    fstream plikTekstowy;
    plikTekstowy.open(nazwaPlikuZAdresatami.c_str(), ios::app);

    if (plikTekstowy.good() == true)
    {
        liniaZDanymiAdresata = zamienDaneAdresataNaLinieZDanymiOddzielonaPionowymiKreskami(adresat);

        if (czyPlikJestPusty() == true)
        {
            plikTekstowy << liniaZDanymiAdresata;
        }
        else
        {
            plikTekstowy << endl << liniaZDanymiAdresata ;
        }
    idOstatniegoAdresata++;
    }
    else
    cout << "Nie udalo sie otworzyc pliku " << nazwaPlikuZAdresatami << " i zapisac w nim danych." << endl;
    plikTekstowy.close();
}

bool PlikZAdresatami::czyPlikJestPusty()
{
    ifstream plikTekstowy(nazwaPlikuZAdresatami.c_str(), ios::in);
    plikTekstowy.seekg(0, ios::end);
    if (plikTekstowy.tellg() == 0)
        return true;
    else
        return false;
}

string PlikZAdresatami::zamienDaneAdresataNaLinieZDanymiOddzielonaPionowymiKreskami(Adresat adresat)
{
    string liniaZDanymiAdresata = "";

    liniaZDanymiAdresata += MetodyPomocnicze::konwerjsaIntNaString(adresat.pobierzId())+ '|';
    liniaZDanymiAdresata += MetodyPomocnicze::konwerjsaIntNaString(adresat.pobierzIdUzytkownika())+ '|';
    liniaZDanymiAdresata += adresat.pobierzImie() + '|';
    liniaZDanymiAdresata += adresat.pobierzNazwisko() + '|';
    liniaZDanymiAdresata += adresat.pobierzNumerTelefonu() + '|';
    liniaZDanymiAdresata += adresat.pobierzEmail() + '|';
    liniaZDanymiAdresata += adresat.pobierzAdres() + '|';

    return liniaZDanymiAdresata;
}


vector <Adresat> PlikZAdresatami::wczytanieAdresatowDoPamieci(int idZalogowanegoUzytkownika) {
    Adresat adresat;
    vector <Adresat> adresaci;
    string daneJednegoAdresataOddzielonePionowymiKreskami = "";
    fstream plikTekstowy;
    plikTekstowy.open(nazwaPlikuZAdresatami.c_str(), ios::in);
    if (plikTekstowy.good() == true) {
        while (getline(plikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami)) {
            if(idZalogowanegoUzytkownika == pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(daneJednegoAdresataOddzielonePionowymiKreskami))
            {
                adresat = pobierzDaneAdresata(daneJednegoAdresataOddzielonePionowymiKreskami);
                adresaci.push_back(adresat);
            }
        }
    }
    ustawIdOstatniegoAdresata(daneJednegoAdresataOddzielonePionowymiKreskami);
    plikTekstowy.close();
    return adresaci;
}

void PlikZAdresatami::ustawIdOstatniegoAdresata(string daneJednegoAdresataOddzielonePionowymiKreskami)
{
    char znak = ' ';
    string wczytywaneIdAdresata="";

    for(int i=0; i<daneJednegoAdresataOddzielonePionowymiKreskami.length(); i++){
        znak = daneJednegoAdresataOddzielonePionowymiKreskami[i];
        if(znak == '|') break;
        else wczytywaneIdAdresata += znak;
    }
    idOstatniegoAdresata = metodyPomocnicze.konwersjaStringNaInt(wczytywaneIdAdresata);
}

int PlikZAdresatami::pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami)
{
    int pozycjaRozpoczeciaIdUzytkownika = daneJednegoAdresataOddzielonePionowymiKreskami.find_first_of('|') + 1;
    int idUzytkownika = metodyPomocnicze.konwersjaStringNaInt(pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdUzytkownika));
    return idUzytkownika;
}

int PlikZAdresatami::pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami)
{
    int pozycjaRozpoczeciaIdAdresata = 0;
    int idAdresata = metodyPomocnicze.konwersjaStringNaInt(pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdAdresata));
    return idAdresata;
}


string PlikZAdresatami::pobierzLiczbe(string tekst, int pozycjaZnaku)
{
    string liczba = "";
    while(isdigit(tekst[pozycjaZnaku]) == true)
    {
        liczba += tekst[pozycjaZnaku];
        pozycjaZnaku ++;
    }
    return liczba;
}


Adresat PlikZAdresatami::pobierzDaneAdresata(string daneJednegoAdresataOddzielonePionowymiKreskami) {
    Adresat adressat;
    string pojedynczaDanaAdresata = "";
    int numerPojedynczejDanejAdresata = 1;

    for (int pozycjaZnaku = 0; pozycjaZnaku < daneJednegoAdresataOddzielonePionowymiKreskami.length(); pozycjaZnaku++) {
        if (daneJednegoAdresataOddzielonePionowymiKreskami[pozycjaZnaku] != '|') {
            pojedynczaDanaAdresata += daneJednegoAdresataOddzielonePionowymiKreskami[pozycjaZnaku];
        } else {
            switch(numerPojedynczejDanejAdresata) {
            case 1:
                adressat.ustawId(atoi(pojedynczaDanaAdresata.c_str()));
                break;
            case 2:
                adressat.ustawIdUzytkownika(atoi(pojedynczaDanaAdresata.c_str()));
                break;
            case 3:
                adressat.ustawImie(pojedynczaDanaAdresata);
                break;
            case 4:
                adressat.ustawNazwisko(pojedynczaDanaAdresata);
                break;
            case 5:
                adressat.ustawNumerTelefonu(pojedynczaDanaAdresata);
                break;
            case 6:
                adressat.ustawEmail(pojedynczaDanaAdresata);
                break;
            case 7:
                adressat.ustawAdres(pojedynczaDanaAdresata);
                break;
            }
            pojedynczaDanaAdresata = "";
            numerPojedynczejDanejAdresata++;
        }
    }
    return adressat;
}

int PlikZAdresatami::pobierzIdOstatniegoAdresata()
{
    return idOstatniegoAdresata;
}

void PlikZAdresatami::zaktualizujDaneWybranegoAdresata(Adresat adresat)
{

    fstream odczytywanyPlikTekstowy, tymczasowyPlikTekstowy;
    string wczytanaLinia = "";
    int numerWczytanejLinii = 1;

    odczytywanyPlikTekstowy.open(nazwaPlikuZAdresatami.c_str(), ios::in);
    tymczasowyPlikTekstowy.open(nazwaTymczasowegoPlikuZAdresatami.c_str(), ios::out | ios::app);

    if (odczytywanyPlikTekstowy.good() == true)
    {
        while (getline(odczytywanyPlikTekstowy, wczytanaLinia))
        {
            if //(numerWczytanejLinii == numerEdytowanejLinii)
                (pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(wczytanaLinia) == adresat.pobierzId())
            {
                if (numerWczytanejLinii == 1)
                    tymczasowyPlikTekstowy << zamienDaneAdresataNaLinieZDanymiOddzielonaPionowymiKreskami(adresat);
                else if (numerWczytanejLinii > 1)
                    tymczasowyPlikTekstowy << endl << zamienDaneAdresataNaLinieZDanymiOddzielonaPionowymiKreskami(adresat);
            }
            else
            {
                if (numerWczytanejLinii == 1)
                    tymczasowyPlikTekstowy << wczytanaLinia;
                else if (numerWczytanejLinii > 1)
                    tymczasowyPlikTekstowy << endl << wczytanaLinia;
            }
            numerWczytanejLinii++;
        }
        odczytywanyPlikTekstowy.close();
        tymczasowyPlikTekstowy.close();

        usunPlik(nazwaPlikuZAdresatami);
        zmienNazwePliku(nazwaTymczasowegoPlikuZAdresatami, nazwaPlikuZAdresatami);
    }

    /*








    string liniaZDanymiAdresata = "";
    fstream plikTekstowy;
    plikTekstowy.open(nazwaPlikuZAdresatami.c_str(), ios::app);

    if (plikTekstowy.good() == true)
    {
        liniaZDanymiAdresata = zamienDaneAdresataNaLinieZDanymiOddzielonaPionowymiKreskami(adresat);

        if (czyPlikJestPusty() == true)
        {
            plikTekstowy << liniaZDanymiAdresata;
        }
        else
        {
            plikTekstowy << endl << liniaZDanymiAdresata ;
        }
    idOstatniegoAdresata++;
    }
    else
    cout << "Nie udalo sie otworzyc pliku " << nazwaPlikuZAdresatami << " i zapisac w nim danych." << endl;
    plikTekstowy.close();








    int numerLiniiEdytowanegoAdresata = 0;
    //string liniaZDanymiAdresata = "";

    numerLiniiEdytowanegoAdresata = zwrocNumerLiniiSzukanegoAdresata(idEdytowanegoAdresata);
    liniaZDanymiAdresata = zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(adresat);
    edytujWybranaLinieWPliku(numerLiniiEdytowanegoAdresata, liniaZDanymiAdresata);

    cout << endl << "Dane zostaly zaktualizowane." << endl << endl;
    */
}

void PlikZAdresatami::usunPlik(string nazwaPlikuZRozszerzeniem)
{
    if (remove(nazwaPlikuZRozszerzeniem.c_str()) == 0) {}
    else
        cout << "Nie udalo sie usunac pliku " << nazwaPlikuZRozszerzeniem << endl;
}

void PlikZAdresatami::zmienNazwePliku(string staraNazwa, string nowaNazwa)
{
    if (rename(staraNazwa.c_str(), nowaNazwa.c_str()) == 0) {}
    else
        cout << "Nazwa pliku nie zostala zmieniona." << staraNazwa << endl;
}
