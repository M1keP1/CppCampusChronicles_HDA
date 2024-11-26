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

    // Modified to take parameters
    void ortAnlegen(const std::string& name, double latitude, double longitude);  // Add a new location with given parameters
    std::string karteAnzeigen() const;  // Display all locations and return as a string
    double entfernungBerechnen(int id1, int id2);  // Calculate distance between two locations by their IDs
    void meinOrtVerschieben(double latitude, double longitude);   // Move MeinOrt to new coordinates
    void karteSpeichern();       // Save the map to a file
    void karteLaden();           // Load the map from a file

private:
    std::vector<Ort*> karte;  // List of all locations (Adresse and PoI)
    Ort* meinOrt;             // Specific location for MeinOrt (initial location)
};

#endif // NAVIGATIONSSYSTEM_H
