#ifndef HERDE_H_H
#define HERDE_H_H
#include <iostream>
using namespace std;


class Herde{

private:
    string Bezeichnung{};
    int anzahl_t{};
    int platzbed_t{};
    bool raub;

public:
    Herde();
    Herde(string Bezeichnung,int anzahl_t,int platzbed_t,bool raub):Bezeichnung(Bezeichnung),anzahl_t(anzahl_t),platzbed_t(platzbed_t),raub(raub){}
    string get_Bezeichnung();
    int get_anzahl_t();
    int get_platzbedarf();
    void increase_anzahl();

};



#endif // HERDE_H_H
