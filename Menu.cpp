
#include <windows.h>
#include "Menu.h"

char Menu::wybierzOpcjeZMenuGlownego()
{
    char wybor = ' ';

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";

    while( 1 ){
        wybor = metodyPomocnicze.wczytajZnak();
        if (wybor == '1' || wybor == '2' || wybor == '9') break;
        else cout<<"Nie ma opcji '"<<wybor<<"', wybierz ponownie"<<endl;
    }

    return wybor;
}

char Menu::wybierzOpcjeZMenuUzytkownika() {
    char wybor;

    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj adresata" << endl;
    cout << "2. Wyszukaj po imieniu" << endl;
    cout << "3. Wyszukaj po nazwisku" << endl;
    cout << "4. Wyswietl adresatow" << endl;
    cout << "5. Usun adresata" << endl;
    cout << "6. Edytuj adresata" << endl;
    cout << "---------------------------" << endl;
    cout << "7. Zmien haslo" << endl;
    cout << "8. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";

    while( 1) {
        wybor = metodyPomocnicze.wczytajZnak();
        if( wybor == '1' || wybor == '2' || wybor == '3' || wybor == '4'|| wybor == '5' || wybor == '6' || wybor == '7' || wybor == '8' ) break;
        else cout<<"Nie ma opcji '"<<wybor<<"', wybierz ponownie"<<endl;
    }
    return wybor;
}
