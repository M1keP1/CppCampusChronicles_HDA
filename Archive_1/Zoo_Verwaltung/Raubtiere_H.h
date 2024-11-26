#ifndef RAUBTIERE_H_H
#define RAUBTIERE_H_H
#include"Zooverwaltung_H.h"

class Raubtiere: public Gehege
{
private:
    bool raubtiere;

public:

    bool aufnehmen(Herde& hn) override;
};


#endif // RAUBTIERE_H_H
