#include "Artikel_header.h"




int Artikel::get_anzahl() const
{
    return anzahl;
}

int Artikel::get_gewicht() const
{
    return (anzahl*gewicht);
}

int Artikel::get_artikelnummer() const
{
    return artikelnummer;
}

string Artikel::get_bezeichnung() const
{
    return bezeichnung;

}

void Artikel::increase_anzahl()
{
    anzahl+=1;
}

bool Artikel::get_flamm() const
{
    return flamm;
}
