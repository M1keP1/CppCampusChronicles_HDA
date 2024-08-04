#ifndef ARTZTPRAXIS_H
#define ARTZTPRAXIS_H
#include "termin.h"

class Artztpraxis
{
private:
    string name /*{"Dr.Koch"}*/;
    vector<Termin> terminliste;
public:
    Artztpraxis();
    Artztpraxis(string name);
    void terminAnlegen(string patient, string datumUhrzeit,Impfstoff vaccine);
    void terminLoeschen(string patient);
    void anzeigen();
    string getName() const;
};

#endif // ARTZTPRAXIS_H
