#ifndef VERSICHERER_H
#define VERSICHERER_H
#include"vschein.h"


class versicherer
{
public:
    versicherer();
    ~ versicherer();
    void dialog();
    void alleanzeigen();
    bool nummerPruefen(int sNummer);
private:
    vector<Vschein*> versicherungen;
};

#endif // VERSICHERER_H
