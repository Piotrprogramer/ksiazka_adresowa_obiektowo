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
bool czyPlikJestPusty();

public:
vector <Adresat> wczytanieAdresatowDoPamieci();
Adresat pobierzDaneAdresata(string daneJednegoAdresataOddzielonePionowymiKreskami);
void dopiszAdresataDoPliku(Adresat adresat);
};

#endif
