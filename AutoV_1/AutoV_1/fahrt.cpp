#include "fahrt.h"



int Fahrt::getAbholdatum() const
{
    return abholdatum;
}

int Fahrt::getAbgabedatum() const
{
    return abgabedatum;
}

double Fahrt::getMietkosten() const
{
    return mietkosten;
}

void Fahrt::setMietkosten(double newMietkosten)
{
    mietkosten = newMietkosten;
}

Fahrt::Fahrt(int n, string k, int ab, int bis):
    nummer(n),
    kunde(k),
    abholdatum(ab),
    abgabedatum(bis)
{

}

void Fahrt::anzeigen()
{
    cout<<"Nr."<<nummer<<": Kunde"<<kunde<<"holt Fahrzeug am"
         << abholdatum <<"ab und bringt es am"<< abgabedatum <<"zurueck"
         <<"with mietkosten"<<fixed << setprecision(2) <<mietkosten<<endl;

}

int Fahrt::getNummer() const
{
    return nummer;
}


