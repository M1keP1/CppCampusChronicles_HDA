#include "arztpraxis.h"
#include <iostream>
using namespace std;

Arztpraxis::Arztpraxis(string name):name(name)
{

}

// --------------- Aufgabe 5: Funktion mit bool ergänzt --------------- //
void Arztpraxis::terminAnlegen(string patient, string datumUhrzeit, Impfstoff impfstoff, bool geloescht){  // Aufgabe 5: Funktion mit bool ergänzt
    Termin termin(patient, datumUhrzeit, impfstoff);
    termin.setGeloescht(geloescht);
    terminListe.push_back(termin);
}

void Arztpraxis::terminAnlegen(string patient, string datumUhrzeit, Impfstoff impfstoff){

    string datum = terminPruefen(datumUhrzeit);
    Termin termin(patient, datum, impfstoff);
    terminListe.push_back(termin); // wenn Termin noch nicht vorhanden, dann in den Vector schreiben

// NUR ZUR PRÜFUNG
    for (unsigned int i=0; i < terminListe.size(); i++){
//        cout << terminListe[i].getPatient() << " um " << terminListe[i].getDatumUhrzeit() << " Bool: " << terminListe[i].getGeloescht() << endl;
    }
    return;
}

bool Arztpraxis::terminLoeschen(string patient){
    bool found = false;
    for (unsigned int i=0; i < terminListe.size(); i++){
        if (terminListe[i].getPatient() == patient && terminListe[i].getGeloescht() == false){
            terminListe[i].setGeloescht(true);

            int komma = patient.find(',');
            string nachname = patient.substr(0,komma);
            string vorname = patient.substr(komma+1,patient.size());
            cout << "Termin " << terminListe[i].getDatumUhrzeit() << " fuer " << vorname << " " << nachname << " geloescht" << endl;
            found = true;
        }
    }

    if(found)
        return true;
    else
        return false;
}

string Arztpraxis::getName() const
{
    return name;
}

vector<Termin> Arztpraxis::getTermine() const
{
    return terminListe;
}

string Arztpraxis::terminPruefen(string datumUhrzeit){
    while (true){
        bool valid = true;
        for (unsigned int i=0; i <terminListe.size(); i++){
            if (terminListe[i].getDatumUhrzeit() == datumUhrzeit){
                cout << "Datum und Uhrzeit schon vergeben. Bitte neu eingeben: ";
                cin >> datumUhrzeit;
                valid = false;
                break;
            }
        }
        if (valid)
            break;
    }
    return datumUhrzeit;
}
