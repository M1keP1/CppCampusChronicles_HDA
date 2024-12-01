#ifndef NAVIGATIONSSYSTEM_H
#define NAVIGATIONSSYSTEM_H

#include "ort.h"
#include "adresse.h"
#include "poi.h"
#include <vector>
#include <string>

class Navigationssystem
{
public:
    Navigationssystem();
    ~Navigationssystem();

    void ortAnlegen();
    std::string karteAnzeigen() const;
    double entfernungBerechnen(int id1, int id2);
    void meinOrtVerschieben(double latitude, double longitude);
    void karteSpeichern();
    void karteLaden();

private:
    std::vector<Ort*> karte;  // List of all locations (Adresse and PoI)
    Ort* meinOrt;             // Specific location for MeinOrt (initial location)
};

#endif // NAVIGATIONSSYSTEM_H
