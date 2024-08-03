#ifndef VSCHEIN_H
#define VSCHEIN_H

#include <string>
using namespace std;

class VSchein
{
public:
    VSchein(int sNummer, string vName, string nName);
    virtual void anzeigen()=0;
    int getScheinNr() const;
    virtual ~VSchein();
    void beitragBerechnen();
    virtual void anpassen();

protected:
    int scheinNummer;
    string vorname;
    string nachname;
    double monatsbeitrag{};
};

#endif // VSCHEIN_H
