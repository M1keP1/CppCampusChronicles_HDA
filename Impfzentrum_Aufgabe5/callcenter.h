#ifndef CALLCENTER_H
#define CALLCENTER_H
#include "arztpraxis.h"
#include <vector>
using namespace std;

class Callcenter
{
public:
    Callcenter();
    ~Callcenter();
    void dialog();
private:
    vector<Arztpraxis> arztpraxen;
    int findeArztpraxis(string name);
    void uebersichtAusgeben(bool storniert);         // Aufgabe 5: bool storniert, um stornierte oder gültige Termine auszugegen
    void speichern();                                // Aufgabe 5: Funktion zum speichern in Datei *****
    void einlesen();                                 // Aufgabe 5: Funktion zum einlesen aus Datei *****
};

#endif // CALLCENTER_H
