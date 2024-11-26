#ifndef GEBAEUDE_H
#define GEBAEUDE_H
#include"wohnung.h"
class Gebaeude
{
public:
    Gebaeude();
    ~Gebaeude();
    void dialog();
private:
    vector<Wohnung*> wohnungsliste;

};

#endif // GEBAEUDE_H
