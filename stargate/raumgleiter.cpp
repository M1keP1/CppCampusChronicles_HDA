#include "raumgleiter.h"



Raumgleiter::Raumgleiter() {
    cout<<"RaumgleiterName?";
    cin>>gleitername;
    cout<<"Maximale Sitzplaetze?";
    cin>>maxPlaetze;
    cout<<"Maximale Ladung?";
    cin>>maxLadung;
    cout<<"Raumgleiter "<<gleitername<<"maximal "<<maxPlaetze
    <<"Platezen und "<<maxLadung<<" kg Nutzlast wurde angelegt"<<endl;
}

void Raumgleiter::flughinzufuegen(Raumflug *rf)
{
    rf->setFlugnummer(++zaehler);
    rf->setMaxLadung(maxLadung);
    rf->setMaxPlaetze(maxPlaetze);
    flugliste.push_back(rf);
    cout<<"Flug "<<rf->getFlugnummer() <<" wurde hinzugefuegt"<<endl;
}

void Raumgleiter::passagierBuchen(int flugnummer)
{
    for(auto&x:flugliste){
        if(x->getFlugnummer()==flugnummer){
            x->addPassagier();
            return;
        }
    }
    cout<<"Raumflug existiert nicht";
}

void Raumgleiter::flugAnzeigen(int flugnummer)
{
    for(auto&x:flugliste){
        if(x->getFlugnummer()==flugnummer){
            x->flugDatenAnzeigen();
            return;
        }
    }
    cout<<"Raumflug existiert nicht";
}

Raumgleiter::~Raumgleiter()
{
    for(auto&x:flugliste){
        delete x;
    }
    flugliste.clear();

}

void Raumgleiter::alleFluegeAnzeigen()
{
    for (auto&x:flugliste) {
        x->flugDatenAnzeigen();
    }
    if(flugliste.size()==0){
        cout<<"There is no flug regitsered";
    }
}

void Raumgleiter::frachtBuchen(int flugnummer)
{
    for(auto&x:flugliste){
        if(x->getFlugnummer()==flugnummer){
            x->addFracht();
            return;
        }
    }
    cout<<"Raumflug existiert nicht";
}
