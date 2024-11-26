#ifndef ARZTPRAXIS_H
#define ARZTPRAXIS_H
#include <vector>
#include "termin.h"
using namespace std;

class Arztpraxis
{
public:
    Arztpraxis(string name);
    void terminAnlegen(string patient, string datumUhrzeit, Impfstoff impfstoff);
    void terminAnlegen(string patient, string datumUhrzeit, Impfstoff impfstoff, bool geloescht); // Aufgabe 5 ergänzt zum Einlesen aus Datei
    bool terminLoeschen(string patient);
    string getName() const;
    vector<Termin> getTermine() const;

private:
    string name = "Dr. Koch";
    vector<Termin> terminListe;
    string terminPruefen(string datumUhrzeit);
};

#endif // ARZTPRAXIS_H
