#ifndef RAUMGLEITER_H
#define RAUMGLEITER_H
#include"raumflug.h"


class raumgleiter
{
public:
    raumgleiter();

    void flugHinzufuegen(raumflug* rf);
    void passagierBuchen(int flugnummer);
    void flugAnzeigen(int flugnummer);
    ~raumgleiter();
    void alleFluegeanzeigen();
    void frachtBuchen(int flugnummer);

    string getGleitename() const;

private:
    string gleitename{};
    unsigned int maxPlatze{};
    double maxLadung{};
    vector<raumflug*>flugListe;
    unsigned int zaehler =10000;
};

#endif // RAUMGLEITER_H
