#ifndef PLIKZADRESATAMI_H
#define PLIKZADRESATAMI_H

#include <vector>
#include <fstream>
#include "Adresat.h"
#include "MetodyPomocnicze.h"

using namespace std;

class PlikZAdresatami
{
    const string nazwaPlikuZAdresatami;
    const string nazwaTymczasowegoPlikuZAdresatami = "TymczasowyPlikZAdresatami";
    int idOstatniegoAdresata;

    string zamienDaneAdresataNaLinieZDanymiOddzielonaPionowymiKreskami(Adresat adresat);
    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    bool czyPlikJestPusty();
    string pobierzLiczbe(string tekst, int pozycjaZnaku);
    void ustawIdOstatniegoAdresata(string daneJednegoAdresataOddzielonePionowymiKreskami);
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    MetodyPomocnicze metodyPomocnicze;


    void usunPlik(string nazwaPlikuZAdresatami);
    void zmienNazwePliku(string nazwaTymczasowegoPlikuZRozszerzeniem, string nazwaPlikuZRozszerzeniem);

public:
    PlikZAdresatami(string NAZWAPLIKUZADRESATAMI):  nazwaPlikuZAdresatami(NAZWAPLIKUZADRESATAMI){};

    int pobierzIdOstatniegoAdresata();
    vector <Adresat> wczytanieAdresatowDoPamieci(int idZalogowanegoUzytkownika);
    Adresat pobierzDaneAdresata(string daneJednegoAdresataOddzielonePionowymiKreskami);
    void dopiszAdresataDoPliku(Adresat adresat);
    void zaktualizujDaneWybranegoAdresata(Adresat adresat);
};

#endif
