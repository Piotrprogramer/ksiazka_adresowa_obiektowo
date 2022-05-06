#ifndef ADRESAT_MENAGER_H
#define ADRESAT_MENAGER_H

#include <vector>
#include <fstream>

#include "AdresatMenager.h"

using namespace std;

class AdresatMenager {
    <vector> Adresat adresaci;

public:
    void wczytanieAdresatowDoPamieci();
    void dodawanieNowegoAdresata();
    void wyswietlWszystkichAdresatow();
};

#endif
