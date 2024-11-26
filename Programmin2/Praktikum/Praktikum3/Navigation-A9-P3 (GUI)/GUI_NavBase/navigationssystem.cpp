#include "navigationssystem.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

// Constructor
Navigationssystem::Navigationssystem()
{
    // Default home address (MeinOrt)
    meinOrt = new Adresse(49.86682, 8.639912, "MeinOrt", "Schöfferstraße", 3, "64295", "Darmstadt");
    meinOrt->setId(0);  // ID for MeinOrt
}

// Destructor
Navigationssystem::~Navigationssystem()
{
    // Clean up the allocated memory for addresses and locations
    for (auto ort : karte) {
        delete ort;
    }
    delete meinOrt;
}

// Function to create a new location (address or POI)
void Navigationssystem::ortAnlegen(const std::string& name, double lat, double lon)
{
    // Ask for location type (Adresse or POI)
    std::string typ;
    std::cout << "Ortstyp (Adresse/POI): ";
    std::cin >> typ;

    if (typ == "Adresse") {
        std::string str, plz, gemeinde;
        int hausnummer;
        std::cout << "Strasse: ";
        std::cin >> str;
        std::cout << "Hausnummer: ";
        std::cin >> hausnummer;
        std::cout << "Postleitzahl: ";
        std::cin >> plz;
        std::cout << "Gemeinde: ";
        std::cin >> gemeinde;

        // Add a new address to the map
        Adresse* newAdresse = new Adresse(lat, lon, name, str, hausnummer, plz, gemeinde);
        karte.push_back(newAdresse);
    } else if (typ == "POI") {
        std::string kat, bem;
        std::cout << "Kategorie: ";
        std::cin >> kat;
        std::cout << "Bemerkung: ";
        std::cin >> bem;

        // Add a new POI to the map
        PoI* newPoI = new PoI(lat, lon, name, kat, bem);
        karte.push_back(newPoI);
    } else {
        std::cout << "Ungültiger Ortstyp!" << std::endl;
    }
}

// Function to display the map with all locations
std::string Navigationssystem::karteAnzeigen() const
{
    std::ostringstream oss;
    if (karte.empty()) {
        oss << "Keine Orte gespeichert." << std::endl;
        return oss.str();
    }

    oss << "Navi-Daten\n";
    oss << "ID | Typ | Name          | Latitude   | Longitude   | Parameters\n";
    oss << "---------------------------------------------------------------\n";

    // Display MeinOrt
    if (meinOrt) {
        auto adresse = dynamic_cast<Adresse*>(meinOrt);
        if (adresse) {
            oss << " 0 | Adr | " << std::setw(13) << adresse->getName() << " | "
                << std::setw(10) << std::fixed << std::setprecision(6) << adresse->getLatitude() << " | "
                << std::setw(10) << std::fixed << std::setprecision(6) << adresse->getLongitude() << " | MeinOrt\n";
        }
    }

    // Display other locations
    for (const auto& ort : karte) {
        oss << std::setw(2) << ort->getId() << " | ";

        if (auto adresse = dynamic_cast<Adresse*>(ort)) {
            oss << "Adr | " << std::setw(13) << adresse->getName() << " | "
                << std::setw(10) << std::fixed << std::setprecision(6) << adresse->getLatitude() << " | "
                << std::setw(10) << std::fixed << std::setprecision(6) << adresse->getLongitude() << " | "
                << adresse->getStrasse() << " " << adresse->getHausnummer() << ", "
                << adresse->getPlz() << " " << adresse->getGemeinde() << "\n";
        } else if (auto poi = dynamic_cast<PoI*>(ort)) {
            oss << "PoI | " << std::setw(13) << poi->getName() << " | "
                << std::setw(10) << std::fixed << std::setprecision(6) << poi->getLatitude() << " | "
                << std::setw(10) << std::fixed << std::setprecision(6) << poi->getLongitude() << " | "
                << poi->getKategorie() << ", " << poi->getBemerkung() << "\n";
        }
    }
    return oss.str();
}

// Function to calculate the distance between two locations
double Navigationssystem::entfernungBerechnen(int id1, int id2)
{
    Ort* ort1 = nullptr;
    Ort* ort2 = nullptr;

    // Check for MeinOrt if ID is 0
    if (id1 == 0) ort1 = meinOrt;
    if (id2 == 0) ort2 = meinOrt;

    // Search for the corresponding IDs in the Karte
    for (auto ort : karte) {
        if (ort->getId() == id1 && id1 != 0) ort1 = ort;
        if (ort->getId() == id2 && id2 != 0) ort2 = ort;
    }

    if (ort1 && ort2) {
        return ort1->berechneEntfernung(*ort2);
    } else {
        std::cout << "Ungültige IDs!" << std::endl;
        return -1;  // Return -1 in case of invalid IDs
    }
}

// Function to move MeinOrt to a new location
void Navigationssystem::meinOrtVerschieben(double latitude, double longitude)
{
    delete meinOrt;  // Free the old memory
    meinOrt = new Adresse(latitude, longitude, "MeinOrt", "Schöfferstraße", 3, "64295", "Darmstadt");
    std::cout << "MeinOrt wurde verschoben." << std::endl;
}

// Function to save the map to a file
void Navigationssystem::karteSpeichern()
{
    std::ofstream outFile("karte.txt");
    if (outFile.is_open()) {
        for (auto ort : karte) {
            if (auto adresse = dynamic_cast<Adresse*>(ort)) {
                outFile << "Adresse "
                        << adresse->getId() << " "
                        << std::fixed << std::setprecision(6) << adresse->getLatitude() << " "
                        << std::fixed << std::setprecision(6) << adresse->getLongitude() << " "
                        << adresse->getName() << " "
                        << adresse->getStrasse() << " "
                        << adresse->getHausnummer() << " "
                        << adresse->getPlz() << " "
                        << adresse->getGemeinde() << std::endl;
            } else if (auto poi = dynamic_cast<PoI*>(ort)) {
                outFile << "POI "
                        << poi->getId() << " "
                        << std::fixed << std::setprecision(6) << poi->getLatitude() << " "
                        << std::fixed << std::setprecision(6) << poi->getLongitude() << " "
                        << poi->getName() << " "
                        << poi->getKategorie() << " "
                        << poi->getBemerkung() << std::endl;
            }
        }
        outFile.close();
        std::cout << "Karte gespeichert!" << std::endl;
    } else {
        std::cout << "Fehler beim Speichern der Karte!" << std::endl;
    }
}

// Function to load the map from a file
void Navigationssystem::karteLaden()
{
    std::ifstream inFile("karte.txt");
    if (inFile.is_open()) {
        std::string line;
        while (std::getline(inFile, line)) {
            std::istringstream ss(line);
            std::string typ;
            ss >> typ;

            double lat, lon;
            ss >> lat >> lon;  // Read latitude and longitude

            if (typ == "Adresse") {
                std::string name, str, plz, gemeinde;
                int hausnummer;
                ss >> name >> str >> hausnummer >> plz >> gemeinde;
                karte.push_back(new Adresse(lat, lon, name, str, hausnummer, plz, gemeinde));
            } else if (typ == "POI") {
                std::string name, kat, bem;
                ss >> name >> kat;
                std::getline(ss, bem);
                karte.push_back(new PoI(lat, lon, name, kat, bem));
            }
        }
        inFile.close();
        std::cout << "Karte geladen!" << std::endl;
    } else {
        std::cout << "Fehler beim Laden der Karte!" << std::endl;
    }
}
