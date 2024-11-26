#ifndef NAVIGATIONSSYSTEM_H
#define NAVIGATIONSSYSTEM_H

#include "ort.h"
#include "adresse.h"
#include "poi.h"
#include <vector>

class Navigationssystem
{
public:
    Navigationssystem();
    ~Navigationssystem();

    void ortAnlegen();           // Add a new location
    void karteAnzeigen() const;  // Display all locations
    void entfernungBerechnen();  // Calculate distance between two locations
    void meinOrtVerschieben();   // Move MeinOrt to new coordinates
    void karteSpeichern();       // Save the map to a file
    void karteLaden();           // Load the map from a file



private:
    std::vector<Ort*> karte;
    Ort* meinOrt;

};

#endif // NAVIGATIONSSYSTEM_H
