#ifndef PLIKZADRESATAMI_H
#define PLIKZADRESATAMI_H

#include <vector>
#include <fstream>
#include "Adresat.h"
#include "MetodyPomocnicze.h"

using namespace std;

class PlikZAdresatami
{
string nazwaPlikuZAdresatami = "Adresaci.txt";
string zamienDaneAdresataNaLinieZDanymiOddzielonaPionowymiKreskami(Adresat adresat);
int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
bool czyPlikJestPusty();
string pobierzLiczbe(string tekst, int pozycjaZnaku);
MetodyPomocnicze metodyPomocnicze;

public:
vector <Adresat> wczytanieAdresatowDoPamieci(int idZalogowanegoUzytkownika);
Adresat pobierzDaneAdresata(string daneJednegoAdresataOddzielonePionowymiKreskami);
void dopiszAdresataDoPliku(Adresat adresat);
};

#endif
