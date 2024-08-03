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
        {
        string moebel_name{};
        cout<<"Enter Moebel name?"<<endl;
        cin>>moebel_name;

        zimmerListe[i]->getMoebelListe().push_back(moebel_name);
        cout<<"Skibidi Toilet added"<<endl;
        found = true;
        }
    }

    if(found==false)
        cout<<"What the sigma?"<<endl;
}
