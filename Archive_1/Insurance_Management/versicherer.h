#ifndef VERSICHERER_H
#define VERSICHERER_H

#include <vector>
#include "vschein.h"

class Versicherer
{
public:
    Versicherer();
    void dialog();
    void nummerpruefen(int sNummer);
private:
    vector<Vschein*> versicherungen;
};


#endif // VERSICHERER_H
