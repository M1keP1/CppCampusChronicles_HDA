#include "ort.h"
#include <cmath>

using namespace std;

// Initialize static ID counter
int Ort::idCounter = 0;

Ort::Ort(double lat, double lon, string name) : latitude(lat), longitude(lon), name(name),id(idCounter++)
{

}

double Ort::berechneEntfernung(const Ort& andererOrt) const
{
    const double pi = 3.14159265358979323846;
    const double erdeRadius = 6371.0; // Earth radius in kilometers

    // Convert degrees to radians
    double lat1 = latitude * pi / 180.0;
    double lon1 = longitude * pi / 180.0;
    double lat2 = andererOrt.getLatitude() * pi / 180.0;
    double lon2 = andererOrt.getLongitude() * pi / 180.0;

    // Haversine formula for distance calculation
    double dlat = lat2 - lat1;
    double dlon = lon2 - lon1;
    double a = sin(dlat / 2) * sin(dlat / 2) +
               cos(lat1) * cos(lat2) * sin(dlon / 2) * sin(dlon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));

    return erdeRadius * c;
}

double Ort::getLatitude() const
{
    return latitude;
}

double Ort::getLongitude() const
{
    return longitude;
}

int Ort::getId() const
{
    return id;
}

std::string Ort::getName() const
{
    return name;
}

void Ort::setId(int newId)
{
    id = newId;
}

void Ort::cleanNeighbors()
{
    neighbors_id.clear();
}

std::vector<int> Ort::getNeighbors_id() const
{
    return neighbors_id;
}

void Ort::setNeighbors_id(int pos, int id)
{
    if (pos >= neighbors_id.size()) {
        neighbors_id.resize(pos + 1); // Resize the vector to fit the position
    }
    neighbors_id[pos] = id;
}
