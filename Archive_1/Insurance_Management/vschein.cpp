#include "vschein.h"

Vschein::Vschein(int sNummer,string vName,string nName):
    scheinNummer(sNummer), vorname(vName), nachname(nName)
{

}

void Vschein::anzeigen()
{
    cout << "VersicherungNr. " << scheinNummer << " fuer " << vorname << " " << nachname << ": " << endl;
}

int Vschein::getScheinNummer() const
{
    return scheinNummer;
}


