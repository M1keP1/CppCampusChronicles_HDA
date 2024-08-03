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

private:
    string marke{};
    string kennzeichen{};
    int sitze{};
    vector<fahrt> fahrtenbuch;
};

#endif // MIETWAGEN_H
