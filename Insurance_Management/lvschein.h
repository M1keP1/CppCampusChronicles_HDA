#ifndef LVSCHEIN_H
#define LVSCHEIN_H
#include "vschein.h"


class LVSchein: public Vschein
{
public:
    LVSchein(int sNummer,string vName,string nName);
    virtual void anzeigen() override;


protected:
    double vSumme{};
    int vBeginn{};
    int laufzeit{};
};

#endif // LVSCHEIN_H
