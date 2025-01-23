#include "navigationssystem.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <QMessageBox>
#include <QInputDialog>
#include <QDialog>
#include <QRadioButton>
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


Ort* Navigationssystem::ortAnlegen() {
    QString name = QInputDialog::getText(nullptr, "Ort anlegen", "Name des Ortes:");
    if (name.isEmpty()) return nullptr; // Return null if cancelled

    QString latitudeText = QInputDialog::getText(nullptr, "Ort anlegen", "Breitengrad:");
    QString longitudeText = QInputDialog::getText(nullptr, "Ort anlegen", "Längengrad:");

    bool latitudeOk, longitudeOk;
    double latitude = latitudeText.toDouble(&latitudeOk);
    double longitude = longitudeText.toDouble(&longitudeOk);

    if (!latitudeOk || !longitudeOk || latitude < -90 || latitude > 90 || longitude < -180 || longitude > 180) {
        QMessageBox::warning(nullptr, "Ungültige Eingabe", "Bitte geben Sie gültige Koordinaten ein.");
        return nullptr; // Return null if invalid input
    }

    QStringList typeOptions = {"Adresse", "POI"};
    bool ok;
    QString typ = QInputDialog::getItem(nullptr, "Ortstyp wählen", "Wählen Sie den Ortstyp:", typeOptions, 0, false, &ok);
    if (!ok) return nullptr; // Return null if cancelled

    Ort* newOrt = nullptr; // Declare a pointer to Ort (base class)

    if (typ == "Adresse") {
        QString str = QInputDialog::getText(nullptr, "Adresse", "Straße:");
        if (str.isEmpty()) return nullptr;

        bool hausnummerOk;
        int hausnummer = QInputDialog::getInt(nullptr, "Adresse", "Hausnummer:", 1, 1, 10000, 1, &hausnummerOk);
        if (!hausnummerOk) return nullptr;

        QString plz = QInputDialog::getText(nullptr, "Adresse", "Postleitzahl:");
        if (plz.isEmpty()) return nullptr;

        QString gemeinde = QInputDialog::getText(nullptr, "Adresse", "Gemeinde:");
        if (gemeinde.isEmpty()) return nullptr;

        newOrt = new Adresse(latitude, longitude, name.toStdString(), str.toStdString(), hausnummer, plz.toStdString(), gemeinde.toStdString());
        karte.push_back(newOrt); // Add to the map

    } else if (typ == "POI") {
        QString kat = QInputDialog::getText(nullptr, "POI", "Kategorie:");
        if (kat.isEmpty()) return nullptr;

        QString bem = QInputDialog::getText(nullptr, "POI", "Bemerkung:");
        if (bem.isEmpty()) return nullptr;

        newOrt = new PoI(latitude, longitude, name.toStdString(), kat.toStdString(), bem.toStdString());
        karte.push_back(newOrt); // Add to the map

    } else {
        QMessageBox::warning(nullptr, "Ungültiger Ortstyp", "Bitte geben Sie einen gültigen Ortstyp (Adresse oder POI) ein.");
        return nullptr; // Return null if invalid type
    }

    return newOrt; // Return the created Ort object
}

string Navigationssystem::karteAnzeigen() const
{
    ostringstream oss;
    if (karte.empty()) {
        oss << "Keine Orte gespeichert." << endl;
        return oss.str();
    }

    oss << "Navi-Daten\n";
    oss << "ID | Typ | Name          | Latitude   | Longitude   | Parameters\n";
    oss << "---------------------------------------------------------------\n";


    if (meinOrt) {
        auto adresse = dynamic_cast<Adresse*>(meinOrt);
        if (adresse) {
            oss << " 0 | Adr | " << setw(13) << adresse->getName() << " | "
                << setw(10) << fixed << setprecision(6) << adresse->getLatitude() << " | "
                << setw(10) << fixed << setprecision(6) << adresse->getLongitude() << " | MeinOrt\n";
        }
    }


    for (const auto& ort : karte) {
        oss << setw(2) << ort->getId() << " | ";

        if (auto adresse = dynamic_cast<Adresse*>(ort)) {
            oss << "Adr | " << setw(13) << adresse->getName() << " | "
                << setw(10) << fixed << setprecision(6) << adresse->getLatitude() << " | "
                << setw(10) << fixed << setprecision(6) << adresse->getLongitude() << " | "
                << adresse->getStrasse() << " " << adresse->getHausnummer() << ", "
                << adresse->getPlz() << " " << adresse->getGemeinde() << "\n";
        } else if (auto poi = dynamic_cast<PoI*>(ort)) {
            oss << "PoI | " << setw(13) << poi->getName() << " | "
                << setw(10) << fixed << setprecision(6) << poi->getLatitude() << " | "
                << setw(10) << fixed << setprecision(6) << poi->getLongitude() << " | "
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
        cout << "Ungültige IDs!" << endl;
        return -1;  // Return -1 in case of invalid IDs
    }
}


void Navigationssystem::meinOrtVerschieben(double latitude, double longitude)
{
    delete meinOrt;
    meinOrt = new Adresse(latitude, longitude, "MeinOrt", "Schöfferstraße", 3, "64295", "Darmstadt");
    cout << "MeinOrt wurde verschoben." << endl;
}


void Navigationssystem::karteSpeichern()
{
    ofstream outFile("karte.txt");
    if (outFile.is_open()) {
        for (auto ort : karte) {
            if (auto adresse = dynamic_cast<Adresse*>(ort)) {
                outFile << "Adresse "
                        << adresse->getId() << " "
                        << fixed << setprecision(6) << adresse->getLatitude() << " "
                        << fixed << setprecision(6) << adresse->getLongitude() << " "
                        << adresse->getName() << " "
                        << adresse->getStrasse() << " "
                        << adresse->getHausnummer() << " "
                        << adresse->getPlz() << " "
                        << adresse->getGemeinde() << endl;
            } else if (auto poi = dynamic_cast<PoI*>(ort)) {
                outFile << "POI "
                        << poi->getId() << " "
                        << fixed << setprecision(6) << poi->getLatitude() << " "
                        << fixed << setprecision(6) << poi->getLongitude() << " "
                        << poi->getName() << " "
                        << poi->getKategorie() << " "
                        << poi->getBemerkung() << endl;
            }
        }
        outFile.close();
        cout << "Karte gespeichert!" << endl;
    } else {
        cout << "Fehler beim Speichern der Karte!" << endl;
    }
}

// Function to load the map from a file
void Navigationssystem::karteLaden()
{
    ifstream inFile("karte.txt");
    if (inFile.is_open()) {
        string line;
        while (getline(inFile, line)) {
            istringstream ss(line);
            string typ;
            ss >> typ;  // Read the type (Adresse or POI)

            // Read the id, latitude, longitude
            int id;
            double lat, lon;
            ss >> id >> lat >> lon;

            // Process POI
            if (typ == "POI") {
                string name, kat, bem;
                ss >> name >> kat;
                getline(ss, bem);  // Read the remainder of the line as the 'bem' (remark/description)

                // Add POI to the map
                karte.push_back(new PoI(lat, lon, name, kat, bem));

            }
            // Process Adresse if needed (not changed in this example)
            else if (typ == "Adresse") {
                string name, str, plz, gemeinde;
                int hausnummer;
                ss >> name >> str >> hausnummer >> plz >> gemeinde;
                karte.push_back(new Adresse(lat, lon, name, str, hausnummer, plz, gemeinde));
            }
        }
        inFile.close();
        cout << "Karte geladen!" << endl;
    } else {
        cout << "Fehler beim Laden der Karte!" << endl;
    }
}

void Navigationssystem::ortDel(Ort* ort)
{
    for (auto it = karte.begin(); it != karte.end(); ++it)
    {
        if (*it == ort)
        {
            karte.erase(it);  // Erase the element pointed to by the iterator
            break;  // Stop the loop once the element is deleted
        }
    }

}



vector<Ort *> Navigationssystem::getKarte() const
{
    return karte;
}
