#ifndef VERSICHERER_H
#define VERSICHERER_H
#include "vschein.h"


class Versicherer
{
public:
    Versicherer();
    void dialog();
    void add();
private:
    vector <Vschein*> versicherungen;
};

#endif // VERSICHERER_H
