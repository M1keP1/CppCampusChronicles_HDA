#include "wohnung.h"

Wohnung::Wohnung() {
    cout<<"Enter Wohnung's name"<<endl;
    cin>>wohnungName;
    cout<<wohnungName<<"Wurde hingefuegt"<<endl;
}

void Wohnung::zimmerHinzufuegen(Zimmer *pz)
{
    zimmerListe.push_back(pz);
    cout<<"Zimmmer"<<pz->getZimmerNummer()<<"Wurde in der wohnungsliste Hinzugefeugt"<<endl;
}

void Wohnung::zimmerAnzeigen(int nummmer)
{
    for(auto& x:zimmerListe){
        if(x->getZimmerNummer()==nummmer){
            x->moebelAnzeigen();
        }
    }
}


void Wohnung::moebelHinzufuegen(int nummer)
{

    for(auto& x:zimmerListe){
        if(x->getZimmerNummer()==nummer){
            x->addMoebel();
            return;
        }
    }
    cout<<"Zimmer dosent exist"<<endl;
}

Wohnung::~Wohnung() {
    for (unsigned int i = 0; i < zimmerListe.size(); i++)
        delete zimmerListe[i];   // dynamisches Objekt vernichten
    zimmerListe.clear();         // aus Vector nehmen
    cout << "Alle Zimmer geloescht" << endl;
}

