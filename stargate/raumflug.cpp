#include "raumflug.h"



void Raumflug::setMaxPlaetze(unsigned int newMaxPlaetze)
{
    _maxPlaetze = newMaxPlaetze;
}

void Raumflug::setMaxLadung(double newMaxLadung)
{
    _maxLadung = newMaxLadung;
}

void Raumflug::setFlugnummer(int newFlugnummer)
{
    flugnummer = newFlugnummer;
}

void Raumflug::addFracht()
{
    string name;
    double weight;
    cout<<"Frachtname?";
    cin>>name;
    cout<<"Frachgewicht?";
    cin>>weight;
    if(weight>(_maxLadung-aktuelleLadung)){
        cout<<"overweight"<<endl;
        return;
    }
    Fracht f1;
    f1.frachtname=name;
    f1.gewicht=weight;
    aktuelleLadung=aktuelleLadung+weight;
    frachtliste.push_back(f1);
    cout<<"Avaibale space"<<(_maxLadung-aktuelleLadung)<<endl;
    return;
}

double Raumflug::zuladungReisender()
{
    double bj;
    bj=((passagierListe.size()*80.0)+(14.6*passagierListe.size()*reisedauer));
    return bj;
}

Raumflug::Raumflug(int f, string d, string z, double r):
    flugnummer(f),
    datum(d),
    ziel(z),
    reisedauer(r)

{

}

void Raumflug::flugDatenAnzeigen()
{
    cout<<"----------------------------"<<endl;
    cout<<"Flugnr "<<flugnummer<<"  Datum:"<<datum<<"  Ziel:"<<ziel<<"  Reisedauer:"<<reisedauer
         <<"places left"<<_maxPlaetze-passagierListe.size()<<endl;
    int j{0};
    for (auto&x:passagierListe) {
        cout<<"Passagier"<<++j<<x<<endl;
    }
    cout<<"Frachtliste:";
    int k{0};
    for (auto&x:frachtliste) {
        cout<<"Fracht"<<++k<<endl;
        cout<<x.frachtname<<endl;
        cout<<x.gewicht<<endl;
        cout<<"struct cost:"<<x.gewicht*6000.0<<endl;
    }
    cout<<"Gesamt cost"<<6000*zuladungReisender();
    cout<<"----------------------------"<<endl;
}

int Raumflug::getFlugnummer()
{
    return flugnummer;
}

void Raumflug::addPassagier()
{
    if(passagierListe.size()>=_maxPlaetze&&aktuelleLadung>=_maxLadung){
        cout<<"Raumflug already full "<<endl;
        return;
    }
    string name;
    cout<<"Name des Passagiers(nachname,vorname)?";
    cin>>name;
    passagierListe.push_back(name);
    aktuelleLadung=zuladungReisender();
    cout<<"Avaibale space"<<(_maxLadung-aktuelleLadung)<<endl;
}
