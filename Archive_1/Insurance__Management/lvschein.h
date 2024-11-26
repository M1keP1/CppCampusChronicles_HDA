#ifndef LVSCHEIN_H
#define LVSCHEIN_H

#include "vschein.h"

class LVSchein : public VSchein
{
public:
    LVSchein(int sNummer, string vName, string nName);
    virtual void anzeigen() override;
    virtual void anpassen() override;
    virtual ~LVSchein();
    double beitragBerechnen();

    void setVSumme(double newVSumme);

protected:
    double vSumme;
    int vBeginn;
    int laufzeit;
    double m;
};

#endif // LVSCHEIN_H
