#ifndef LAGERPLATZ_HEADER_H
#define LAGERPLATZ_HEADER_H
#include <iostream>
#include<string>
#include "Artikel_func.cpp"
using namespace std;

class Lagerplatz
{
private:
    int platz_id{};
    double kapazitat{};
    double max_gewicht{};

public:
    Lagerplatz();
    Lagerplatz(double max_gewicht):max_gewicht(){}

    int get_platz_id() const;
    double get_kapazitat() const;
    int get_max_gewicht() const;
    int get_gewicht() const ;

    void set_platz_id();
    void set_kapazitat();
    void set_max_gewicht();

    virtual bool einlagern(Artikel&);
    void platz_inventur() const;

    vector<Artikel> artikeln;


};


#endif // LAGERPLATZ_HEADER_H
