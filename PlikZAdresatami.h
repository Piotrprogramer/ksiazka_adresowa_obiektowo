#ifndef PLIKZADRESATAMI_H
#define PLIKZADRESATAMI_H

#include <iostream>
#include <vector>
#include <fstream>

#include "Adresat.h"
#include "MetodyPomocnicze.h"
#include "PlikTekstowy.h"

using namespace std;

class PlikZAdresatami :public PlikTekstowy{

    const string nazwaTymczasowegoPlikuZAdresatami = "TymczasowyPlikZAdresatami";
    int idOstatniegoAdresata = 0;

    string zamienDaneAdresataNaLinieZDanymiOddzielonaPionowymiKreskami(Adresat adresat);
    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    string pobierzLiczbe(string tekst, int pozycjaZnaku);
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    void usunPlik(string nazwaPlikuZRozszerzeniem);
    void zmienNazwePliku(string staraNazwa, string nowaNazwa);

public:
    PlikZAdresatami(string NAZWAPLIKUZADRESATAMI):  PlikTekstowy(NAZWAPLIKUZADRESATAMI){};

    int pobierzIdOstatniegoAdresata();
    vector <Adresat> wczytanieAdresatowDoPamieci(int idZalogowanegoUzytkownika);
    Adresat pobierzDaneAdresata(string daneJednegoAdresataOddzielonePionowymiKreskami);
    void dopiszAdresataDoPliku(Adresat adresat);
    void aktualizujDaneWybranegoAdresataWPliku(Adresat adresat);
    void usunWybranegoAdresata(int idUsuwanegoAdresata);
};
#endif
