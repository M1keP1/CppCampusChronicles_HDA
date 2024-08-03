#ifndef KFZSCHEIN_H
#define KFZSCHEIN_H

#include "vschein.h"

class KFZSchein : public VSchein
{
public:
    KFZSchein(int sNummer, string vName, string nName);
    virtual void anzeigen() override;
    virtual ~KFZSchein();
    double beitragBerechnen();
    virtual void anpassen() override;


    void setKfzKennzeichen(const string &newKfzKennzeichen);

protected:
    string kfzKennzeichen;
    int vBeginn;
    int schadenfreiJahre{};
    double m;

};

#endif // KFZSCHEIN_H
