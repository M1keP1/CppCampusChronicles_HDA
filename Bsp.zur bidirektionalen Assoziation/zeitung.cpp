#include "zeitung.h"
#include <iostream>

// Konstruktor
Zeitung::Zeitung () {
    cout << "Bitte geben Sie den Namen der Zeitung ein: ";
    cin >> name;

    cout << "Die Zeitung mit dem Namen " << name << " wurde erstellt!" << endl;

}

void Zeitung::addAbonnent(Abonnent* pA) {
    abonnenten.push_back(pA);  // wenn Zeitung viele Abonnenten erlaubt
}


string Zeitung::getName() const
{
    return name;
}


// wenn Zeitung viele Abonnenten erlaubt
vector<Abonnent *> Zeitung::getAbonnenten() const
{
    return abonnenten;
}
