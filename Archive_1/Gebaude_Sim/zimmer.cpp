#include "zimmer.h"
Zimmer::Zimmer(int z): zimmerNummer(z)
{

}

int Zimmer::getZimmernummer()
{
    return zimmerNummer;
}

void Zimmer::setZimmerNummer(int newZimmerNummer)
{
    zimmerNummer = newZimmerNummer;
}

vector<string> Zimmer::getMoebelListe() const
{
    return moebelListe;
}

void Zimmer::setMoebelListe(const vector<string> &newMoebelListe)
{
    moebelListe = newMoebelListe;
}



void Zimmer::addMoebel()
{
    string moebel_name{};
    cout<<"Enter Moebel name?"<<endl;
    cin>>moebel_name;

    moebelListe.push_back(moebel_name);
    cout<<"Skibidi Toilet added"<<endl;
}

void Zimmer::moebelAnzeigen()
{
    for(const auto &x: moebelListe)
    {
        cout<<x<<endl;
    }
}

