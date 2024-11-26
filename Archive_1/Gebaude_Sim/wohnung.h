#ifndef WOHNUNG_H
#define WOHNUNG_H
#include "zimmer.h"


class Wohnung
{
private:
    string wohnungsName;
    vector<Zimmer*> zimmerListe;
public:
    Wohnung();
    void zimmerHinzufuegen(Zimmer* pZ);
    void zimmerAnzeigen(int nummer);
    void moebelHinzufuegen(int nummer);
};

#endif // WOHNUNG_H
