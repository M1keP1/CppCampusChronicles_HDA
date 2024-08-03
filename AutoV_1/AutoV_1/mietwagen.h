#ifndef MIETWAGEN_H
#define MIETWAGEN_H
#include"fahrt.h"
#include"iomanip"
class Mietwagen
{
private:
    string marke;
    string kennzeichen;
    int sitze;
    vector<Fahrt>fahrenbuch;
    double tagespreis;

public:
    Mietwagen();
    void anmieten(Fahrt f);
    void fahrtAnzeigen(int nummer);
    void alleFahrtenAnzeigen();
    bool nummerPruefen(int nummer);
    bool fahrtLoeschen(int nummer);
    bool verfuegbarkeitPruefen(Fahrt f);
    void fahrzeugAnzeigen();
    int berechneTage(int datum);

};

#endif // MIETWAGEN_H
