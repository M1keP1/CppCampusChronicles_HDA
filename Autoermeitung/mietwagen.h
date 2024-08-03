#ifndef MIETWAGEN_H
#define MIETWAGEN_H
#include"fahrt.h"



class mietwagen
{
public:
    mietwagen();
    void anmieten(fahrt f);
    void fahrtAnzeigen(int nummer);
    void alleFahrtenAnzeigen();
    vector<fahrt> getFahrtenbuch() const;
    bool nummerPruefen(int nummer);
    bool fahrtloeschen(int nummer);
    bool verfuegbarkeitPruefen(fahrt f);
    void fahrzeugAnzeigen();

    string getMarke() const;

    string getKennzeichen() const;


    double getTagespreis() const;
    double gesamtUmsatz();

private:
    string marke{};
    string kennzeichen{};
    int sitze{};
    vector<fahrt> fahrtenbuch;
    double tagespreis{};
protected:
    int berechneTage(int datum);
};

#endif // MIETWAGEN_H
