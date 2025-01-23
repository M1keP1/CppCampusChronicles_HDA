#ifndef NAVIGATIONSSYSTEM_H
#define NAVIGATIONSSYSTEM_H
#include <QString>
#include <map>

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
    void karteSpeichern(const std::string& filename);
    void karteLaden(const std::string& filename);
    void ortDel(Ort* ort);
    void createGraph();
    void clearKarte();
    void updateNeighbors();
    vector<Ort *> getKarte() const;

    map<int, vector<pair<int, double> > > getGraph() const;
    vector<int> findShortestPath(int startId, int endId);
private:
    map<int, vector<pair<int, double>>> graph;
    vector<Ort*> karte;  // List of all locations (Adresse and PoI)
    Ort* meinOrt;             // Specific location for MeinOrt (initial location)
};

#endif // NAVIGATIONSSYSTEM_H
