#ifndef ZEITUNGSVERLAG_H
#define ZEITUNGSVERLAG_H

#include "zeitung.h"
#include "abonnent.h"


class ZeitungsVerlag {
public:
    ZeitungsVerlag ();     // Konstruktor
    void dialog();         // Hauptschleife
    Abonnent* getAbonnent();
    Zeitung* getZeitung();

private:
    vector<Zeitung*> zeitungsListe;
    vector<Abonnent*> abonenntenListe;
};



#endif // ZEITUNGSVERLAG_H
