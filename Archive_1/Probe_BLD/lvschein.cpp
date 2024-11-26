#include "lvschein.h"


LVSchein::~LVSchein()
{

}

LVSchein::LVSchein(int scheinNummer, string vorname, string nachname):
    Vschein(scheinNummer,vorname,nachname)
{
    cout<<"Versicherungssumme?"<<endl;
    cin>>vSumme;
    cout<<"Versicherungsbegin (Jahr)? "<<endl;
    cin>>vBeginn;
    cout<<"Laufzeit in Jahren? "<<endl;
    cin>>laufzeit;
   monatsbeitrag = beitragBerechnen();
    cout<<"Versicherung LV mit "<<scheinNummer<<"Wurde erstellt"<<endl;
}

void LVSchein::anzeigen()
{
    cout<<"Lebensversicherung ueber"<<vSumme<<" Euro seit"<<vBeginn<<"mit Laufzeit von"<<laufzeit
         <<"Jahren "<<"und Monatsbeitrag von "<<fixed<<setprecision(2)<<monatsbeitrag<<"Euro"<<endl;
}

double LVSchein::beitragBerechnen()
{
    return (vSumme/10000)*3.52;
}

void LVSchein::anpassen()
{
    cout<<"Der alte Monatsbeitrag ist "<<beitragBerechnen()<<endl;
    cout<<"Neue LV-Summe:"<<endl;
    cin>>vSumme;
    cout<<"Der Monatsbeitrag der LV betraegt nun"<<beitragBerechnen()<<"Euro"<<endl;
}
