#include "termin.h"
using namespace std;

Termin::Termin(string patient, string datumUhrzeit, Impfstoff impfstoff):
        datumUhrzeit(datumUhrzeit), patient(patient), impfstoff(impfstoff){
}

string Termin::getPatient() const
{
    return patient;
}

string Termin::getDatumUhrzeit() const
{
    return datumUhrzeit;
}

bool Termin::getGeloescht() const
{
    return geloescht;
}

void Termin::setGeloescht(bool value)
{
    geloescht = value;
}

Impfstoff Termin::getImpfstoff() const
{
    return impfstoff;
}

// Aufgabe 4: operator<  überladen für sort() in Callcenter::uebersichtAusgeben

bool Termin::operator<(const Termin& t) {   // Aufgabe 4 bei Nutzung von sort()
    return getPatient() < t.getPatient();
}
