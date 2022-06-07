#ifndef PLIKZADRESATAMI_H
#define PLIKZADRESATAMI_H

#include <vector>
#include <fstream>
#include "Adresat.h"
#include "MetodyPomocnicze.h"
#include "PlikTekstowy.h"

using namespace std;

class PlikZAdresatami
{
    MetodyPomocnicze metodyPomocnicze;
    PlikTekstowy plikTekstowy;

    const string nazwaPlikuZAdresatami;
    const string nazwaTymczasowegoPlikuZAdresatami = "TymczasowyPlikZAdresatami";
    int idOstatniegoAdresata;

    string zamienDaneAdresataNaLinieZDanymiOddzielonaPionowymiKreskami(Adresat adresat);
    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    bool czyPlikJestPusty();
    string pobierzLiczbe(string tekst, int pozycjaZnaku);
    void ustawIdOstatniegoAdresata(string daneJednegoAdresataOddzielonePionowymiKreskami);
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);

public:
    PlikZAdresatami(string NAZWAPLIKUZADRESATAMI):  nazwaPlikuZAdresatami(NAZWAPLIKUZADRESATAMI){};

    int pobierzIdOstatniegoAdresata();
    vector <Adresat> wczytanieAdresatowDoPamieci(int idZalogowanegoUzytkownika);
    Adresat pobierzDaneAdresata(string daneJednegoAdresataOddzielonePionowymiKreskami);
    void dopiszAdresataDoPliku(Adresat adresat);
    void aktualizujDaneWybranegoAdresataWPliku(Adresat adresat);
    void usunWybranegoAdresata(int idUsuwanegoAdresata);
};

#endif
