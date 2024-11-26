#include "fahrt.h"



fahrt::fahrt(int n, string k, int ab, int bis):nummer(n),kunde(k),abholdatum(ab),abgabedatum(bis)
{

}

void fahrt::anzeigen()
{
    cout<<"Nr. "<<nummer<<": Kunde "<<kunde<<" holt Fahrzeug am "<<abholdatum<<" ab und bringt es am "<<abgabedatum<<" zuruck"<<"    " <<endl;
}

int fahrt::getNummer() const
{
    return nummer;
}

int fahrt::getAbholdatum() const
{
    return abholdatum;
}

int fahrt::getAbgabedatum() const
{
    return abgabedatum;
}







