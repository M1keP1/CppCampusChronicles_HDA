#ifndef RAUMFAHRTUNTERNEHMEN_H
#define RAUMFAHRTUNTERNEHMEN_H
#include "raumgleiter.h"

class Raumfahrtunternehmen
{
private:
    vector<Raumgleiter*> gleiterListe;
public:
    double berechneDauer(string ziel, double resiedauer);
    Raumfahrtunternehmen();
    void dialog();
    ~Raumfahrtunternehmen();
};

#endif // RAUMFAHRTUNTERNEHMEN_H
