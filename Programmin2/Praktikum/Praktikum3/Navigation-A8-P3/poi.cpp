#include "poi.h"
#include <iostream>

PoI::PoI(double lat, double lon, std::string name, std::string kat, std::string bem)
    : Ort(lat, lon, name), kategorie(kat), bemerkung(bem) {}

void PoI::anzeigen() const
{
    // Include ID and standardize the output format
    std::cout << "ID: " << getId() << " | POI: " << kategorie << " - " << bemerkung
              << " (Latitude: " << getLatitude() << ", Longitude: " << getLongitude() << ")"
              << std::endl;
}

std::string PoI::getKategorie() const
{
    return kategorie;
}

std::string PoI::getBemerkung() const
{
    return bemerkung;
}
