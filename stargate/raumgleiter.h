#ifndef RAUMGLEITER_H
#define RAUMGLEITER_H
#include"raumflug.h"

class Raumgleiter
{
private:
    string gleitername;
    unsigned int maxPlaetze;
    double maxLadung;
    vector<Raumflug*> flugliste;
    unsigned int zaehler{1000};
public:
    Raumgleiter();
    void flughinzufuegen(Raumflug* rf);
    void passagierBuchen(int flugnummer);
    void flugAnzeigen(int flugnummer);
    ~Raumgleiter();
    void alleFluegeAnzeigen();
    void frachtBuchen(int flugnummer);


};

#endif // RAUMGLEITER_H
