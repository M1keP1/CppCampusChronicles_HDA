#include "lvschein.h"




LVSchein::LVSchein(int sNummer, string vName, string nName):
    Vschein(sNummer,vName,nName)
{
    cout<<"Enter Summe?"<<endl;
    cin>> vSumme;
    cout<<"Beginn?"<<endl;
    cin>> vBeginn;
    cout<<"Laufzeit?"<<endl;
    cin>> laufzeit;

}
