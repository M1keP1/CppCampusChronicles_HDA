#include "lvschein.h"
#include <iostream>


// Konstruktor
LVSchein::LVSchein(int sNummer, string vName, string nName):
    VSchein(sNummer, vName, nName)
{
    cout << "Versicherungssumme? ";
    cin >> vSumme;
    cout << "Versicherungsbegin (Jahr)? ";
    cin >> vBeginn;
    cout << "Laufzeit in Jahren? ";
    cin >> laufzeit;
    monatsbeitrag=beitragBerechnen();
}

void LVSchein::anzeigen()
{
    VSchein::anzeigen();
    cout << "Lebensversicherung ueber " << vSumme << " Euro seit "
         << vBeginn << " mit Laufzeit von " << laufzeit << " Jahren" << "Monatsbeitrag : "<<monatsbeitrag<<endl;
}

void LVSchein::anpassen()
{
    double nvSumme;
    cout<<"Enter new VSumme"<<endl;
    cin>>nvSumme;
    cout<<"Alte Monatsbeitrag: "<<monatsbeitrag<<endl;
    setVSumme(nvSumme);
    cout<<"Neue monatsbeitrag: "<<beitragBerechnen()<<endl;

}

LVSchein::~LVSchein()
{

}

double LVSchein::beitragBerechnen()
{
    return (vSumme/10000)*3.52;
}

void LVSchein::setVSumme(double newVSumme)
{
    vSumme = newVSumme;
}
