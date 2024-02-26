#ifndef GEHEGE_H_H
#define GEHEGE_H_H
#include<iostream>
#include <vector>
#include "Herde_H.h"
using namespace std;

class Gehege{
private:
    int ID;
    int max_capacity{};
    int actual_capacity{};
    bool raubtier{};
    vector<Herde> herds;


public:
    Gehege();
    Gehege(int ID,int max_capacity,bool raubtier):ID(ID),max_capacity(max_capacity),raubtier(raubtier){}

    bool virtual aufnehmen(Herde&);
    int getPlatz();
    int get_actual_capacity();
    int get_ID();
    int get_max_capacity();
    vector<Herde> get_herd();
    bool get_raubtier();
    void set_raubtier();



};

#endif // GEHEGE_H_H
