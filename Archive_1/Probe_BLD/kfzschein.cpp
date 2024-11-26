#include "kfzschein.h"


KFZSchein::~KFZSchein()
{

}

KFZSchein::KFZSchein(int scheinNummer, string vorname, string nachname):

    Vschein(scheinNummer,vorname,nachname)

{
    cout<<"KFZ-Kennzeichen?"<<endl;
    cin.ignore(10,'\n');
    getline(cin,kfzKennzeischen);
    cout<<"Versicherungsbegin (Jahr)? "<<endl;
    cin>>vBeginn;
    schadensfreiejahre=2024-vBeginn;
    if(schadensfreiejahre<0){
        schadensfreiejahre=0;
    }
    monatsbeitrag = beitragBerechnen();
    cout<<"Versicherung KFZ mit "<<scheinNummer<<"Wurde erstellt"<<endl;
}

void KFZSchein::anzeigen()
{
    cout<<"KFZ-Versicherung "<<kfzKennzeischen<<"seit "<<vBeginn<<"mit der SF-Klasse SF "
         <<schadensfreiejahre<<" und Monatsbeitrag von "<<fixed<<setprecision(2)<<monatsbeitrag<<"Euro"<<endl;
}

void KFZSchein::setKfzKennzeischen(const string &newKfzKennzeischen)
{
    kfzKennzeischen = newKfzKennzeischen;
}

double KFZSchein::beitragBerechnen()
{
    switch (schadensfreiejahre) {
    case 0:
        return 1.5*68.74;
        break;
    case 1:
        return 68.74;
        break;
    case 2:
        return 0.85*68.74;
        break;
    case 3:
        return 0.7*68.74;
        break;
    default:
        return ((50-schadensfreiejahre)/100.0)*68.74;
        break;
    }

}

void KFZSchein::anpassen()
{
    char eingabe;
    cout<<"Bitte waehlen Sie U fuer einen Unfall melden oder W fuer Fahrzeug wechseln"<<endl;
    cin>>eingabe;
    if(eingabe=='W'){
        cout<<"Neues KFZ-Kennzeichen?";
        cin>>kfzKennzeischen;
        cout<<"Versicherung auf"<<kfzKennzeischen<<" umgeschrieben"<<endl;
        return;
    }
    schadensfreiejahre=schadensfreiejahre-6;
    if(schadensfreiejahre<0){
        schadensfreiejahre=0;
    }
    cout<<"Rueckstufung in SF"<<schadensfreiejahre<<"Monatsbeitrag stieg auf"<<beitragBerechnen()<<"Euro"<<endl;
}
