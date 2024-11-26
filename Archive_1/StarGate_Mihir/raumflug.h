#ifndef RAUMFLUG_H
#define RAUMFLUG_H
#include<iostream>
#include<vector>
using namespace std;

struct Fracht{
    string frachtname;
    double gewicht;
};

class raumflug
{
public:
    raumflug(int f,string d,string z,double r);
    void flugDatenAnzeigen();
    void addPassagier();

    int getFlugnummer() const;

    void setMaxPlaetze(int newMaxPlaetze);

    void setMaxLadung(double newMaxLadung);

    void setFlugnummer(int newFlugnummer);
    void addFracht();
    double zuladungReisender();




private:
    int flugnummer{};
    string datum{};
    string ziel{};
    double reisedauer{};
    vector<string>passagierListe;
    int _maxPlaetze{};
    double _maxLadung{};
    double aktuelleladung =0.0;
    vector <Fracht> frachtListe;


};

#endif // RAUMFLUG_H
