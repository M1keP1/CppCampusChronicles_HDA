#include "kfzschein.h"
#include <iostream>
#include<iomanip>
// Konstruktor
KFZSchein::KFZSchein(int sNummer, string vName, string nName):
    VSchein(sNummer, vName, nName)
{
    cout << "KFZ-Kennzeichen? ";
    cin.ignore(10,'\n');
    getline(cin, kfzKennzeichen);  // umgesetzt mit getline um auch Leerzeichen einzulesen
    cout << "Versicherungsbegin (Jahr)? ";
    cin >> vBeginn;
    schadenfreiJahre=2024-vBeginn;
    if(schadenfreiJahre<0)
    {
        schadenfreiJahre=0;
    }
    monatsbeitrag=beitragBerechnen();
}

void KFZSchein::anzeigen()
{
    VSchein::anzeigen();
    cout << "KFZ-Versicherung " << kfzKennzeichen << " seit " << vBeginn << "SF :" <<schadenfreiJahre<<"Monatsbeitrag :"<<fixed<<setprecision(2)<<monatsbeitrag<< endl;
}

KFZSchein::~KFZSchein()
{

}

double KFZSchein::beitragBerechnen()
{
    if(schadenfreiJahre==0)
    {
        return 1.5*68.74;
    }
    if(schadenfreiJahre==1)
    {
        return 1*68.74;
    }
    if(schadenfreiJahre==2)
    {
        return 0.85*68.74;
    }
    if(schadenfreiJahre==3)
    {
        return 0.7*68.74;
    }
    if(schadenfreiJahre==4)
    {
        return 0.55*68.74;
    }

    return (((50-schadenfreiJahre)/100.0)*68.74);

}

void KFZSchein::anpassen()
{
    double alt_beitrag=monatsbeitrag;
    char choice3{};
    cout<<" Auswahl zwischen U für „Unfall melden“ oder W für „Fahrzeug wechseln“"<<endl;
    cin>>choice3;
    if(choice3=='U'||choice3=='u')
    {
        schadenfreiJahre=schadenfreiJahre-6;
        if(schadenfreiJahre<0)schadenfreiJahre=0;
        cout<<"Rückstufung in Schadensfreiheitsklasse SF"<<schadenfreiJahre<< "erfolgte"<<endl;
                cout<<"Monatsbeitrag stieg von"<<alt_beitrag<<" Euro auf"<<beitragBerechnen()<< "Euro"<<endl;
    }
    if(choice3=='W'||choice3=='w')
    {
        string newkfzKennzeichen{};
        cout<<"Enter new KFZkennzeichen"<<endl;
        cin>>newkfzKennzeichen;
        setKfzKennzeichen(newkfzKennzeichen);
    }
}

void KFZSchein::setKfzKennzeichen(const string &newKfzKennzeichen)
{
    kfzKennzeichen = newKfzKennzeichen;
}


