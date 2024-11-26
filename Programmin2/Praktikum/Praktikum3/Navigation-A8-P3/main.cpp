#include <iostream>
#include "navigationssystem.h"

using namespace std;

int main()
{
    Navigationssystem navSys;
    int wahl;

    do {
        cout << "\nNavigationssystem\n";
        cout << "1) Ort anlegen\n";
        cout << "2) Karte anzeigen\n";
        cout << "3) Entfernung berechnen\n";
        cout << "4) MeinOrt verschieben\n";
        cout << "5) Karte speichern/laden\n";
        cout << "0) Programm verlassen\n";
        cout << "Ihre Wahl: ";
        cin >> wahl;

        switch (wahl) {
        case 1:
            navSys.ortAnlegen();
            break;
        case 2:
            navSys.karteAnzeigen();
            break;
        case 3:
            navSys.entfernungBerechnen();
            break;
        case 4:
            navSys.meinOrtVerschieben();
            break;
        case 5:
        {
            int subwahl;
            cout << "1) Karte speichern\n";
            cout << "2) Karte laden\n";
            cout << "Ihre Wahl: ";
            cin >> subwahl;
            if (subwahl == 1) {
                navSys.karteSpeichern();
            } else if (subwahl == 2) {
                navSys.karteLaden();
            } else {
                cout << "Ungültige Auswahl!" << endl;
            }
            break;
        }
        case 0:
            cout << "Programm beendet!" << endl;
            break;
        default:
            cout << "Ungültige Auswahl!" << endl;
            break;
        }
    } while (wahl != 0);

    return 0;
}
