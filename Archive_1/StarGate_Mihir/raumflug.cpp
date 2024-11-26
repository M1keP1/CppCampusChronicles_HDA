#include "raumflug.h"
#include <iomanip>



raumflug::raumflug(int f, string d, string z, double r):flugnummer(f),datum(d),ziel(z),reisedauer(r)
{

}

void raumflug::flugDatenAnzeigen()
{
    cout<<"-------------------------------------------------------------------"<<endl;
    cout<<"FlugNr. "<<flugnummer<<"\t Datum: "<<datum<<"\t Ziel: "<<ziel<<"\t Reisedauer : "<<reisedauer<<endl;
    cout<<"Seats left: "<<(_maxPlaetze-passagierListe.size())<<endl;
    for(auto& x:passagierListe)
    {
        cout<<"Passagier : "<<x;
        cout<<"***"<<endl;

    }
    cout<<"Passenger costs : "<<zuladungReisender()*6000<<endl;
    for(auto& x:frachtListe)
    {
        cout<<"Fracht : "<<x.frachtname<<"\t Gew: "<<x.gewicht<<"\t Cost: "<<x.gewicht*6000.0<<endl;
        cout<<"***"<<endl;

    }

    cout<<"Capacity left: "<<(_maxLadung-aktuelleladung)<<endl;
    cout<<"=+++++========++=++=+=+=========="<<endl;
    cout<<"Cost estimate : "<<fixed<<setprecision(2)<<aktuelleladung*6000<<endl;

}

void raumflug::addPassagier()
{
    if((passagierListe.size())==_maxPlaetze)
    {
        cout<<"No more seats!!"<<endl;
        return;
    }

    if((aktuelleladung+zuladungReisender()+80+(reisedauer*14.6))>_maxLadung)
    {
        cout<<"Weight limit reached!!"<<endl;
        return;
    }

    string name{};
    cout<<"Enter Name : ";
    cin>>name;

    passagierListe.push_back(name);
    aktuelleladung+=80+(reisedauer*14.6);

    cout<<"Added Succesfully!!!"<<endl;
    cout<<"Current Ladung : "<<aktuelleladung<<endl;
    cout<<"Capcity left : "<<_maxLadung-aktuelleladung<<endl;
}

int raumflug::getFlugnummer() const
{
    return flugnummer;
}

void raumflug::setMaxPlaetze(int newMaxPlaetze)
{
    _maxPlaetze = newMaxPlaetze;
}

void raumflug::setMaxLadung(double newMaxLadung)
{
    _maxLadung = newMaxLadung;
}

void raumflug::setFlugnummer(int newFlugnummer)
{
    flugnummer = newFlugnummer;
}

void raumflug::addFracht()
{
    string nam;
    double gew;
    cout<<"Enter name of fracht : ";
    cin>>nam;
    cout<<"Enter Weight of fracht : ";
    cin>>gew;
    if(gew+aktuelleladung>_maxLadung)
    {
        cout<<"No more place!!"<<endl;
        return;
    }
    Fracht f1;
    f1.frachtname=nam;
    f1.gewicht=gew;
    frachtListe.push_back(f1);
    cout<<"Fracht added!!"<<endl;
    aktuelleladung+=gew;
    cout<<"Current Ladung : "<<aktuelleladung<<endl;
    cout<<"Capcity left : "<<_maxLadung-aktuelleladung<<endl;
}

double raumflug::zuladungReisender()
{
    double bodygew{};
    double oxygew{};
    double totalgew{};
    bodygew=(passagierListe.size()*80.0);
    oxygew=(passagierListe.size()*14.6*reisedauer);
    totalgew=bodygew+oxygew;
    return totalgew;


}

