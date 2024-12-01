#include "navigationssystem.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <QMessageBox>
#include <QInputDialog>
#include <QDialog>
using namespace std;
// Constructor
Navigationssystem::Navigationssystem()
{
    // Default home address (MeinOrt)
    meinOrt = new Adresse(49.86682, 8.639912, "MeinOrt", "Schöfferstraße", 3, "64295", "Darmstadt");
    meinOrt->setId(0);
}


Navigationssystem::~Navigationssystem()
{

    for (auto ort : karte) {
        delete ort;
    }
    delete meinOrt;
}


void Navigationssystem::ortAnlegen()
{

    QString name = QInputDialog::getText(nullptr, "Ort anlegen", "Name des Ortes:");
    if (name.isEmpty()) return;

    QString latitudeText = QInputDialog::getText(nullptr, "Ort anlegen", "Breitengrad:");
    QString longitudeText = QInputDialog::getText(nullptr, "Ort anlegen", "Längengrad:");

    bool latitudeOk, longitudeOk;
    double latitude = latitudeText.toDouble(&latitudeOk);
    double longitude = longitudeText.toDouble(&longitudeOk);

    if (!latitudeOk || !longitudeOk || latitude < -90 || latitude > 90 || longitude < -180 || longitude > 180) {
       QMessageBox::warning(nullptr, "Ungültige Eingabe", "Bitte geben Sie gültige Koordinaten ein.");
       return;
    }


    QStringList typeOptions = {"Adresse", "POI"};
    bool ok;
    QString typ = QInputDialog::getItem(nullptr, "Ortstyp wählen", "Wählen Sie den Ortstyp:", typeOptions, 0, false, &ok);
    if (!ok) return;

    if (typ == "Adresse") {

        QString str = QInputDialog::getText(nullptr, "Adresse", "Straße:");
        if (str.isEmpty()) return;

        bool hausnummerOk;
        int hausnummer = QInputDialog::getInt(nullptr, "Adresse", "Hausnummer:", 1, 1, 10000, 1, &hausnummerOk);
        if (!hausnummerOk) return;

        QString plz = QInputDialog::getText(nullptr, "Adresse", "Postleitzahl:");
        if (plz.isEmpty()) return;

        QString gemeinde = QInputDialog::getText(nullptr, "Adresse", "Gemeinde:");
        if (gemeinde.isEmpty()) return;


        Adresse* newAdresse = new Adresse(latitude, longitude, name.toStdString(), str.toStdString(), hausnummer, plz.toStdString(), gemeinde.toStdString());
        karte.push_back(newAdresse);
        return;
    } else if (typ == "POI") {

        QString kat = QInputDialog::getText(nullptr, "POI", "Kategorie:");
        if (kat.isEmpty()) return;

        QString bem = QInputDialog::getText(nullptr, "POI", "Bemerkung:");
        if (bem.isEmpty()) return;


        PoI* newPoI = new PoI(latitude, longitude, name.toStdString(), kat.toStdString(), bem.toStdString());
        karte.push_back(newPoI);


    } else {

        QMessageBox::warning(nullptr, "Ungültiger Ortstyp", "Bitte geben Sie einen gültigen Ortstyp (Adresse oder POI) ein.");
    }
}

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


    if (meinOrt) {
        auto adresse = dynamic_cast<Adresse*>(meinOrt);
        if (adresse) {
            oss << " 0 | Adr | " << std::setw(13) << adresse->getName() << " | "
                << std::setw(10) << std::fixed << std::setprecision(6) << adresse->getLatitude() << " | "
                << std::setw(10) << std::fixed << std::setprecision(6) << adresse->getLongitude() << " | MeinOrt\n";
        }
    }


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


double Navigationssystem::entfernungBerechnen(int id1, int id2)
{
    Ort* ort1 = nullptr;
    Ort* ort2 = nullptr;


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


void Navigationssystem::meinOrtVerschieben(double latitude, double longitude)
{
    delete meinOrt;
    meinOrt = new Adresse(latitude, longitude, "MeinOrt", "Schöfferstraße", 3, "64295", "Darmstadt");
    std::cout << "MeinOrt wurde verschoben." << std::endl;
}


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
            ss >> lat >> lon;

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
