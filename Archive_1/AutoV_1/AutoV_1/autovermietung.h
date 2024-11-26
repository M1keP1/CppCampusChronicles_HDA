#ifndef AUTOVERMIETUNG_H
#define AUTOVERMIETUNG_H
#include"mietwagen.h"

class autovermietung
{
private:
    vector<Mietwagen*> fahrzeuge;

public:
    void dialog();
    autovermietung();
    ~autovermietung();
    vector<Mietwagen *> getFahrzeuge() const;
    int mietwagensuche();
};

#endif // AUTOVERMIETUNG_H
