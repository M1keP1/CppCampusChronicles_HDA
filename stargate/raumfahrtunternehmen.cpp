#include "raumfahrtunternehmen.h"

double Raumfahrtunternehmen::berechneDauer(string ziel, double resiedauer)
{
    return 1.0;
}

Raumfahrtunternehmen::Raumfahrtunternehmen() {}

void Raumfahrtunternehmen::dialog()
{
    int eingabe;
    Raumgleiter*pRaumgleiter=new Raumgleiter;
    gleiterListe.push_back(pRaumgleiter);
    int flugnummer;
    string datum;
    string ziel;
    double reisedauer;
    unsigned int gleiterIndex=0;

    while (true) {
        cout<<"1: Raumflug hinzufuegen"<<endl;
        cout<<"2: Raumflug buchen"<<endl;
        cout<<"3: Raumflug anzeigen"<<endl;
        cout<<"4: Alle fluganzeigen"<<endl;
        cout<<"5: Fracht buchen"<<endl;
        cout<<"0: Program beenden"<<endl;
        cin>>eingabe;

        switch (eingabe) {
        case 1:{
            /*cout<<"Flugnummer?";
            cin>>flugnummer;*/
            cout<<"Abflug?";
            cin>>datum;
            cout<<"Resieziel?";
            cin>>ziel;
            cout<<"Reise dauer in Tagen?";
            cin>>reisedauer;
            Raumflug *rf=new Raumflug(0,datum,ziel,reisedauer);
            pRaumgleiter->flughinzufuegen(rf);
        }
            break;
        case 2:{
            cout<<"Flugnummer?";
            cin>>flugnummer;
            pRaumgleiter->passagierBuchen(flugnummer);

        }
        break;
        case 3:{
            cout<<"Flugnummer?";
            cin>>flugnummer;
            pRaumgleiter->flugAnzeigen(flugnummer);
        }
        break;
        case 4:{
            pRaumgleiter->alleFluegeAnzeigen();
        }
        break;
        case 5:{
            cout<<"Flugnummer?";
            cin>>flugnummer;
            pRaumgleiter->frachtBuchen(flugnummer);
        }
        break;
        case 6:{
            gleiterIndex=gleiterListe.size();
            Raumgleiter*r2=new Raumgleiter;
            gleiterListe.push_back(r2);
        }
        break;
        case 0:
            return;
        break;
        default:
            cout<<"Enter number between 0 to 4";
            break;
        }

    }
}

Raumfahrtunternehmen::~Raumfahrtunternehmen()
{
    for (auto&x:gleiterListe) {
        delete x;
    }
    gleiterListe.clear();
    cout<<"Ich bin Groot!"<<endl;
}
