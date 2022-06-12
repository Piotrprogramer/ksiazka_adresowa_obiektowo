#ifndef Menu_H
#define Menu_H
#include <iostream>

#include "MetodyPomocnicze.h"

using namespace std;

class Menu{
    MetodyPomocnicze metodyPomocnicze;

public:
    char wybierzOpcjeZMenuGlownego();
    char wybierzOpcjeZMenuUzytkownika();
};

#endif
