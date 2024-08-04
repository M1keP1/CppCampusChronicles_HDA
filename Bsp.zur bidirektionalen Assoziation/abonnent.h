#ifndef ABONNENT_H
#define ABONNENT_H

#include <string>
#include <vector>
using namespace std;

class Zeitung; //Vorwärtsdeklaration


class Abonnent {
public:
    Abonnent();       // Konstruktor

    void abonniere(Zeitung* zeitung);
    vector<Zeitung *> getMeineZeitungen() const;
    string getName() const;

private:
    vector<Zeitung*> meineZeitungen;
    string name = "";
};


#endif // ABONNENT_H
