#ifndef KFZSCHEIN_H
#define KFZSCHEIN_H
#include "vschein.h"


class KFZSchein: public Vschein
{
public:
    KFZSchein(int sNummer,string vName,string nName);
    virtual void anzeigen() override;


protected:
    string kfzKennzeichen{};
    int vBegin{};
};

#endif // KFZSCHEIN_H
