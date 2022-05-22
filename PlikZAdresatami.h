#ifndef PLIKZADRESATAMI_H
#define PLIKZADRESATAMI_H

#include <vector>
#include <fstream>
#include "Adresat.h"
#include "MetodyPomocnicze.h"

using namespace std;

class PlikZAdresatami
{
    string NAZWA_PLIKU_Z_ADRESATAMI = "Adresaci.txt";
    int idOstatniegoAdresata;

    string zamienDaneAdresataNaLinieZDanymiOddzielonaPionowymiKreskami(Adresat adresat);
    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    bool czyPlikJestPusty();
    string pobierzLiczbe(string tekst, int pozycjaZnaku);
    void ustawIdOstatniegoAdresata(string daneJednegoAdresataOddzielonePionowymiKreskami);
    MetodyPomocnicze metodyPomocnicze;

public:

    int pobierzIdOstatniegoAdresata();
    vector <Adresat> wczytanieAdresatowDoPamieci(int idZalogowanegoUzytkownika);
    Adresat pobierzDaneAdresata(string daneJednegoAdresataOddzielonePionowymiKreskami);
    void dopiszAdresataDoPliku(Adresat adresat);
};

#endif
