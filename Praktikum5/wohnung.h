#ifndef WOHNUNG_H
#define WOHNUNG_H
#include"zimmer.h"

class Wohnung
{
public:
    Wohnung();
    void zimmerHinzufuegen(Zimmer*pz);
    void zimmerAnzeigen(int nummmer);
    void moebelHinzufuegen(int nummer);
    ~Wohnung();

private:
    string wohnungName;
    vector<Zimmer*>zimmerListe;


};

#endif // WOHNUNG_H
