#include "zimmer.h"

Zimmer::Zimmer(int z):
    zimmerNummer(z)
{}

void Zimmer::moebelAnzeigen()
{
    int j{0};
    cout<<"Zimmernummer"<<zimmerNummer<<"hat folgende Moebel:"<<endl;
    for (auto& z: moebelListe) {
        cout<<++j<<z<<endl;
    }
}

int Zimmer::getZimmerNummer() const
{
    return zimmerNummer;
}

vector<string> Zimmer::getMoebelListe() const
{
    return moebelListe;
}

void Zimmer::addMoebel(){
    string moebel;
    cout << "Name des Moebelstuecks? ";
    cin >> moebel;
    moebelListe.push_back(moebel);
    cout << moebel << " wurde dem Zimmer " << zimmerNummer << " hinzugefuegt" << endl;
}
