#ifndef RAUMFAHRTUNTERNEHMEN_H
#define RAUMFAHRTUNTERNEHMEN_H
#include"raumgleiter.h"

class raumfahrtunternehmen
{
public:
    raumfahrtunternehmen();
    ~ raumfahrtunternehmen();

    void dialog();
    int berechnerDauer();
private:
    vector<raumgleiter*>gleiterListe;


};

#endif // RAUMFAHRTUNTERNEHMEN_H
