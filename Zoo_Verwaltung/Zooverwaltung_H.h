#ifndef ZOOVERWALTUNG_H_H
#define ZOOVERWALTUNG_H_H
#include "Gehege_H.h"

class Zooverwaltung
{
private:
    vector<Gehege>gehegen;



public:
    void zooErweitern(int platz,bool raubtier);
    bool aufnehmen_nachID(int ID,Herde& herde);
    bool aufnehmen(Herde& herde);
    void inventur();
    int get_gesamt_actual_capacity();
    int get_gesamt_max_capacity();
    int get_gesamt_platzbedarf();
    vector<Gehege> get_gehege();
};

#endif // ZOOVERWALTUNG_H_H
