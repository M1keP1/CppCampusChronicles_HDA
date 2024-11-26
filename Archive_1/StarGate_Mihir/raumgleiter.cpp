#include "raumgleiter.h"

raumgleiter::raumgleiter()
{
    cout<<"Enter name of Glider: ";
    cin>>gleitename;
    cout<<"Enter max seats: ";
    cin>>maxPlatze;
    cout<<"Enter max Ladung: ";
    cin>>maxLadung;
    cout<<"Glider added!!"<<endl;
}

raumgleiter::~raumgleiter()
{
    for(auto& x:flugListe)
    {
        delete x;
    }
    flugListe.clear();
    cout<<"Ich bin groot!!"<<endl;
}

void raumgleiter::alleFluegeanzeigen()
{
    if(flugListe.empty())cout<<"Noch keine Fluege vorhanden"<<endl;
    for(auto& x: flugListe)
    {
        x->flugDatenAnzeigen();
    }
}

void raumgleiter::frachtBuchen(int flugnummer)
{

    for(auto& x:flugListe)
    {
        if(x->getFlugnummer()==flugnummer)
        {
            x->addFracht();
            return;
        }

    }
    cout<<"Nicht gefunden !!"<<endl;
}

string raumgleiter::getGleitename() const
{
    return gleitename;
}

void raumgleiter::flugHinzufuegen(raumflug *rf)
{
    rf->setFlugnummer(zaehler++);
    rf->setMaxPlaetze(maxPlatze);
    rf->setMaxLadung(maxLadung);
    flugListe.push_back(rf);
}

void raumgleiter::passagierBuchen(int flugnummer)
{
    for(auto& x:flugListe)
    {
        if(x->getFlugnummer()==flugnummer)
        {
            x->addPassagier();
            return;
        }

    }
    cout<<"Nicht gefunden !!"<<endl;
}

void raumgleiter::flugAnzeigen(int flugnummer)
{
    for(auto& x:flugListe)
    {
        if(x->getFlugnummer()==flugnummer)
        {
            x->flugDatenAnzeigen();
            return;
        }

    }
    cout<<"Nicht gefunden !!"<<endl;
}
