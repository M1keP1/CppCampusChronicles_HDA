#ifndef GEBAEUDE_H
#define GEBAEUDE_H

#include "wohnung.h"


class Gebaeude
{
private:
    vector <Wohnung*> wohnungsListe;
public:
    Gebaeude();
    void dialog();
    vector<Wohnung *> getWohnungsListe() const;
    void setWohnungsListe(const vector<Wohnung *> &newWohnungsListe);
};

#endif // GEBAEUDE_H
