#include "wohnung.h"

Wohnung::Wohnung()
{

}

void Wohnung::zimmerHinzufuegen(Zimmer *pZ)
{
    zimmerListe.push_back(pZ);
    cout<<"Zimmer added"<<endl;
}

void Wohnung::zimmerAnzeigen(int nummer)
{
    bool found= false;
    for(int i = 0; i<zimmerListe.size();i++)
    {
        if(zimmerListe[i]->getZimmernummer()==nummer)
            zimmerListe[i]->moebelAnzeigen();
        found = true;
    }

    if(found==false)
        cout<<"What the sigma?"<<endl;
}

void Wohnung::moebelHinzufuegen(int nummer)
{
    bool found= false;
    for(int i = 0; i<zimmerListe.size();i++)
    {
        if(zimmerListe[i]->getZimmernummer()==nummer)
            zimmerListe[i]->addMoebel();

        found = true;
    }

    if(found==false)
        cout<<"What the sigma?"<<endl;
}
