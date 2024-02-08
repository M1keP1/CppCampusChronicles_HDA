#ifndef LAGERVERWALTUNG_HEADER_H
#define LAGERVERWALTUNG_HEADER_H
#include "Lagerplatz_func.cpp"

class Lagerverwaltung
{
private:
    vector<Lagerplatz> platzen;

public:

    bool lagerErweitern(double maxGewicht);
    bool einlagern(const Artikel& artikel);
    bool einlagernNachId(int id, Artikel& artikel);
    void inventur();
    double get_total_gewicht();
    double get_total_kapazitat();

};

#endif // LAGERVERWALTUNG_HEADER_H
