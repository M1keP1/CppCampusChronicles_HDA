#ifndef NAVIGATIONSSYSTEM_H
#define NAVIGATIONSSYSTEM_H
#include <QString>

#include "ort.h"
#include "adresse.h"
#include "poi.h"
using namespace std;
#include <vector>
#include <string>
struct Coordinates {
    double latitude;
    double longitude;

    Coordinates(double lat = 0.0, double lon = 0.0) : latitude(lat), longitude(lon) {}
};

class Navigationssystem
{
public:
    Navigationssystem();
    ~Navigationssystem();

    Ort* ortAnlegen();
    string karteAnzeigen() const;
    double entfernungBerechnen(int id1, int id2);
    void meinOrtVerschieben(double latitude, double longitude);
    void karteSpeichern();
    void karteLaden();
    void ortDel(Ort* ort);

    vector<Ort *> getKarte() const;

private:
    vector<Ort*> karte;  // List of all locations (Adresse and PoI)
    Ort* meinOrt;             // Specific location for MeinOrt (initial location)
};

#endif // NAVIGATIONSSYSTEM_H
