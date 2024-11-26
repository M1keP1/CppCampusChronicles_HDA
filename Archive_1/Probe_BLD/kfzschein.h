#ifndef KFZSCHEIN_H
#define KFZSCHEIN_H
#include"vschein.h"


class KFZSchein : public Vschein
{
public:
    virtual ~KFZSchein();
    KFZSchein(int scheinNummer,string vorname,string nachname);
    virtual void anzeigen() override;
    void setKfzKennzeischen(const string &newKfzKennzeischen);
    double beitragBerechnen();
    virtual void anpassen() override;

private:
    string kfzKennzeischen;
    int vBeginn;
    int schadensfreiejahre;
     double monatsbeitrag;
};

#endif // KFZSCHEIN_H
