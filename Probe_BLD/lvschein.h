#ifndef LVSCHEIN_H
#define LVSCHEIN_H
#include"vschein.h"

class LVSchein : public Vschein
{
public:
    virtual ~LVSchein();
    LVSchein(int scheinNummer,string vorname,string nachname);
    virtual void anzeigen() override;
    double beitragBerechnen();
    virtual void anpassen() override;
private:
    double vSumme;
    int vBeginn;
    int laufzeit;
    double monatsbeitrag;
};

#endif // LVSCHEIN_H
