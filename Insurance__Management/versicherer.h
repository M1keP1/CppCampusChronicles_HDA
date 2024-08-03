#ifndef VERSICHERER_H
#define VERSICHERER_H

#include <vector>
#include "vschein.h"

class Versicherer
{
public:
    Versicherer();
    void dialog();
    bool nummerpruefen(int sNummer);
    virtual ~Versicherer();
private:
    vector<VSchein*> versicherungen;
};


#endif // VERSICHERER_H
