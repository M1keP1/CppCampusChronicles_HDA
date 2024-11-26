#ifndef AUTOVERMEITUNG_H
#define AUTOVERMEITUNG_H

#include "mietwagen.h"



class autovermeitung
{
public:
    autovermeitung();
    void dialog();

    vector<mietwagen *> getFahrzeuge() const;

private:
    vector<mietwagen*> fahrzeuge;



};

#endif // AUTOVERMEITUNG_H
