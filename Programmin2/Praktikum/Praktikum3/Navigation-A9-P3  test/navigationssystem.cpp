#include "navigationssystem.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

Navigationssystem::Navigationssystem()
{
    //default home
     meinOrt = new Adresse(49.86682, 8.639912, "MeinOrt", "Schöfferstraße", 3, "64295", "Darmstadt");
    meinOrt->setId(0);
}


void Navigationssystem::ortAnlegen()
{
    std::string typ;
    std::cout << "Ortstyp (A/P): ";
    std::cin >> typ;

    double lat, lon;
    std::cout << "Latitude: ";
    std::cin >> lat;
    std::cout << "Longitude: ";
    std::cin >> lon;

    std::string name;
    std::cout << "Name: ";
    std::cin.ignore();
    std::getline(std::cin, name);

    if (typ == "Adresse") {
        std::string str, plz, gemeinde;
        int hausnummer;
        std::cout << "Strasse: ";
        std::getline(std::cin, str);
        std::cout << "Hausnummer: ";
        std::cin >> hausnummer;
        std::cout << "Postleitzahl: ";
        std::cin >> plz;
        std::cout << "Gemeinde: ";
        std::cin.ignore();
        std::getline(std::cin, gemeinde);

        karte.push_back(new Adresse(lat, lon, name, str, hausnummer, plz, gemeinde));
    } else if (typ == "POI") {
        std::string kat, bem;
        std::cout << "Kategorie: ";
        std::getline(std::cin, kat);
        std::cout << "Bemerkung: ";
        std::getline(std::cin, bem);

        karte.push_back(new PoI(lat, lon, name, kat, bem));
    } else {
        std::cout << "Ungültiger Ortstyp!" << std::endl;
    }
}

void Navigationssystem::meinOrtVerschieben()
{
    double lat, lon;
    std::cout << "Geben Sie den neuen Breitengrad für MeinOrt: ";
    std::cin >> lat;
    std::cout << "Geben Sie den neuen Längengrad für MeinOrt: ";
    std::cin >> lon;

    delete meinOrt; // Free the old memory
    meinOrt = new Adresse(lat, lon, "MeinOrt", "Schöfferstraße", 3, "64295", "Darmstadt");
    std::cout << "MeinOrt wurde verschoben." << std::endl;
}

void Navigationssystem::entfernungBerechnen()
{
    int id1, id2;
    std::cout << "Geben Sie die ID des ersten Ortes ein: ";
    std::cin >> id1;
    std::cout << "Geben Sie die ID des zweiten Ortes ein: ";
    std::cin >> id2;

    Ort* ort1 = nullptr;
    Ort* ort2 = nullptr;

    // Check if ID corresponds to MeinOrt
    if (id1 == 0) ort1 = meinOrt;
    if (id2 == 0) ort2 = meinOrt;

    // Search in Karte for other IDs
    for (auto ort : karte) {
        if (ort->getId() == id1 && id1 != 0) ort1 = ort;
        if (ort->getId() == id2 && id2 != 0) ort2 = ort;
    }

    if (ort1 && ort2) {
        double entfernung = ort1->berechneEntfernung(*ort2);
        std::cout << "Die Entfernung zwischen den Orten beträgt: " << entfernung << " km" << std::endl;
    } else {
        std::cout << "Ungültige IDs!" << std::endl;
    }
}

void Navigationssystem::karteSpeichern()
{
    std::ofstream outFile("karte.txt");
    if (outFile.is_open()) {
        for (auto ort : karte) {
            if (auto adresse = dynamic_cast<Adresse*>(ort)) {

                // Write Adresse data to file with proper formatting
                outFile << "Adresse "
                        << adresse->getId() << " "
                        << std::fixed << std::setprecision(6) << adresse->getLatitude() << " "
                        << std::fixed << std::setprecision(6) << adresse->getLongitude() << " "
                        <<adresse->getName()<<" "
                        << adresse->getStrasse() << " "
                        << adresse->getHausnummer() << " "
                        << adresse->getPlz() << " "
                        << adresse->getGemeinde() << std::endl;
            } else if (auto poi = dynamic_cast<PoI*>(ort)) {

                // Write PoI data to file with proper formatting
                outFile << "POI "
                        << poi->getId() << " "
                        << std::fixed << std::setprecision(6) << poi->getLatitude() << " "
                        << std::fixed << std::setprecision(6) << poi->getLongitude() << " "
                        <<poi->getName()<<" "
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
             // Declare the 'name' variable here
            ss >> lat >> lon;  // Read the name after latitude and longitude


            if (typ == "A") {
                std::string  name, str, plz, gemeinde;
                int hausnummer;
                ss >>  name>> str >> hausnummer >> plz >> gemeinde;
                karte.push_back(new Adresse(lat, lon, name, str, hausnummer, plz, gemeinde));
            } else if (typ == "P") {
                std::string name,kat, bem;
                ss >> name>>kat;
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

Navigationssystem::~Navigationssystem()
{
    for (auto ort : karte) {
        delete ort;
    }
    delete meinOrt;
}

void Navigationssystem::karteAnzeigen() const
{

    if (karte.empty()) {
        std::cout << "Keine Orte gespeichert." << std::endl;
        return;
    }

    std::cout << "Navi-Daten\n";
    std::cout << "ID | Typ | Name          | Latitude   | Longitude   | Parameters\n";
    std::cout << "---------------------------------------------------------------\n";

    // Display MeinOrt
    if (meinOrt) {
        auto adresse = dynamic_cast<Adresse*>(meinOrt);
        if (adresse) {
            std::cout << " 0 | Adr | " << std::setw(13) << adresse->getName() << " | "
                      << std::setw(10) << std::fixed << std::setprecision(6) << adresse->getLatitude() << " | "
                      << std::setw(10) << std::fixed << std::setprecision(6) << adresse->getLongitude() << " | MeinOrt\n";
        }
    }

    for (const auto& ort : karte) {
        std::cout << std::setw(2) << ort->getId() << " | ";

        if (auto adresse = dynamic_cast<Adresse*>(ort)) {
            std::cout << "Adr | " << std::setw(13) << adresse->getName() << " | "
                      << std::setw(10) << std::fixed << std::setprecision(6) << adresse->getLatitude() << " | "
                      << std::setw(10) << std::fixed << std::setprecision(6) << adresse->getLongitude() << " | "
                      << adresse->getStrasse() << " " << adresse->getHausnummer() << ", "
                      << adresse->getPlz() << " " << adresse->getGemeinde() << "\n";
        } else if (auto poi = dynamic_cast<PoI*>(ort)) {
            std::cout << "PoI | " << std::setw(13) << poi->getName() << " | "
                      << std::setw(10) << std::fixed << std::setprecision(6) << poi->getLatitude() << " | "
                      << std::setw(10) << std::fixed << std::setprecision(6) << poi->getLongitude() << " | "
                      << poi->getKategorie() << ", " << poi->getBemerkung() << "\n";
        }
    }
}
