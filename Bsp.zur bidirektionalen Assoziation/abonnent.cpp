#include <iostream>
#include "abonnent.h"

 // Konstruktor
Abonnent::Abonnent () {
    cout << "Bitte geben Sie den Namen des Abonnenten ein: ";
    cin >> name;

    cout << "Der Abonnent mit dem Namen " << name << " wurde erstellt!" << endl;
}

void Abonnent::abonniere(Zeitung* zeitung) {
    meineZeitungen.push_back(zeitung);
}

vector<Zeitung *> Abonnent::getMeineZeitungen() const
{
    return meineZeitungen;
}

string Abonnent::getName() const
{
    return name;
}
