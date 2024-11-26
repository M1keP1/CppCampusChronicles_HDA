#include "adresse.h"
#include <iostream>

Adresse::Adresse(double lat, double lon,std::string name, std::string str, int nr, std::string p, std::string g)
    : Ort(lat, lon,name), strasse(str), hausnummer(nr), plz(p), gemeinde(g) {}

void Adresse::anzeigen() const
{
    // Include ID and standardize the output format
    std::cout << "ID: " << getId() << " | Adresse: " << strasse << " " << hausnummer << ", "
              << plz << " " << gemeinde << " (Latitude: " << getLatitude()
              << ", Longitude: " << getLongitude() << ")" << std::endl;
}

std::string Adresse::getStrasse() const
{
    return strasse;
}

int Adresse::getHausnummer() const
{
    return hausnummer;
}

std::string Adresse::getPlz() const
{
    return plz;
}

std::string Adresse::getGemeinde() const
{
    return gemeinde;
}
