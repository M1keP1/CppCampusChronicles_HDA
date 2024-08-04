#ifndef ZEITUNG_H
#define ZEITUNG_H

#include <string>
#include <vector>
using namespace std;

class Abonnent; //Vorwärtsdeklaration


class Zeitung {
public:
    Zeitung ();
    void addAbonnent(Abonnent* pA);
    string getName() const;
    vector<Abonnent *> getAbonnenten() const;  // wenn Zeitung viele Abonnenten erlaubt

private:
    vector<Abonnent*> abonnenten;              // wenn Zeitung viele Abonnenten erlaubt
    string name = "";
};


#endif // ZEITUNG_H
