#include "vschein.h"

Vschein::Vschein(int scheinNummer,string vorname,string nachname):
    scheinNummer(scheinNummer),
    vorname(vorname),
    nachname(nachname)
{}

void Vschein::anzeigen()
{
    cout<<"VersicherungNr."<<scheinNummer<<"fuer"<<vorname<<nachname<<endl;
}

int Vschein::getScheinNummer() const
{
    return scheinNummer;
}

Vschein::~Vschein()
{
    cout << "Versicherung mit der Nummer " << scheinNummer << " ist entgueltig tot" << endl;
}

void Vschein::anpassen()
{

}


