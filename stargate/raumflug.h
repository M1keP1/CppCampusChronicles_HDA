#ifndef RAUMFLUG_H
#define RAUMFLUG_H
#include<iostream>
#include <vector>

using namespace std;

struct Fracht{
    string frachtname;
    double gewicht;
};

class Raumflug
{
private:
    int flugnummer;
    string datum;
    string ziel;
    double reisedauer;
    vector<string>passagierListe;
    unsigned int _maxPlaetze;
    double _maxLadung;
    double aktuelleLadung {0.0};
    vector<Fracht> frachtliste;
public:
    Raumflug(int f, string d,string z,double r);
    void flugDatenAnzeigen();
    int getFlugnummer();
    void addPassagier();
    void setMaxPlaetze(unsigned int newMaxPlaetze);
    void setMaxLadung(double newMaxLadung);
    void setFlugnummer(int newFlugnummer);
    void addFracht();
    double zuladungReisender();
};

#endif // RAUMFLUG_H
