#include "vschein.h"
#include <iostream>

VSchein::VSchein(int sNummer, string vName, string nName):
    scheinNummer(sNummer), vorname(vName), nachname(nName)
{


}

int VSchein::getScheinNr() const
{
    return scheinNummer;
}

VSchein::~VSchein()
{

}

void VSchein::beitragBerechnen()
{

}

void VSchein::anpassen()
{

}

void VSchein::anzeigen(){
    cout << "VersicherungNr. " << scheinNummer << " fuer " << vorname << " " << nachname << ": " << endl;
}
